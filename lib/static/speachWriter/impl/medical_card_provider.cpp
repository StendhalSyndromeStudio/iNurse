#include "medical_card_provider.h"
#include "medical_card.h"
#include "property_provider.h"
#include "property_form_provider.h"
#include "interfaces/iproperty.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

MedicalCardProvider::MedicalCardProvider()
{

}

MedicalCardProvider::~MedicalCardProvider()
{

}

namespace
{
  QJsonObject toJson(IMedicalCard *card);
  QJsonObject toJson(IPropertyForm *form);

  QJsonObject toJson(IMedicalCard *card) {
    auto json = toJson( dynamic_cast<IPropertyForm*>( card ) );

    QJsonArray formsArray;
    for ( auto child: card->forms() ) {
      formsArray.append( toJson( child ) );
    }

    json[ "child_forms" ] = formsArray;
    return json;
  }

  QJsonObject toJson(IPropertyForm *form) {
    QJsonObject json;
    QJsonArray arr;

    for ( auto &prop: form->properties() ) {
      QJsonObject obj;
      obj[ "id" ]     = prop->id();
      obj[ "type" ]   = prop->type();
      obj[ "value" ]  = prop->value().toString();
     arr.append( obj );
    }
    json[ "props" ] = arr;
    return json;
  }

  IMedicalCard *mediacalCardFromFile(const QString &path);
  IMedicalCard *mediacalCardFromJson(const QJsonObject &obj);
  void loadMediacalCardFromJson(IMedicalCard *card, const QJsonObject &obj);

  IPropertyForm *formFromJson(const QJsonObject &obj);
  void loadFormFromJson(IPropertyForm *form, const QJsonObject &obj);

  IMedicalCard *mediacalCardFromFile(const QString &path) {
      QFile f ( path );
      if ( f.open( QIODevice::ReadOnly ) ) {
        auto json = QJsonDocument::fromJson( f.readAll() ).object();
        f.close();
        return mediacalCardFromJson( json );
      }
      return nullptr;
  }

  IMedicalCard *mediacalCardFromJson(const QJsonObject &obj) {
    auto card = MedicalCardProvider().create();
    loadMediacalCardFromJson( card, obj );

    if ( card->fio().isEmpty() || card->docSerial().isEmpty() || card->docNumber().isEmpty() ) {
      delete card;
      card = nullptr;
    }

    return card;
  }

  void loadMediacalCardFromJson(IMedicalCard *card, const QJsonObject &obj){
    loadFormFromJson( card, obj );

    QJsonArray arr = obj[ "child_forms" ].toArray();
    for ( int i = 0; i < arr.count(); ++i ) {
      auto obj = arr.at( i ).toObject();
      auto form = formFromJson( obj );
      if ( form )
        card->add( form );
    }
  }

  IPropertyForm *formFromJson(const QJsonObject &obj){
    auto form = PropertyFormProvider().create( obj[ "type" ].toString() );
    if ( form )
      loadFormFromJson(form, obj);
    return form;
  }

  void loadFormFromJson(IPropertyForm *form, const QJsonObject &obj){
    auto arr = obj[ "props" ].toArray();
    for  ( int i = 0; i < arr.count(); ++i ) {
      auto obj = arr.at( i ).toObject();
      form->property( obj[ "id" ].toString(), obj[ "type" ].toString() )
          ->setValue( obj[ "value" ].toString() );

    }
  }
}

#include <QDir>
#include <QFile>
#include <QCoreApplication>
bool MedicalCardProvider::save(IMedicalCard *card) const
{
  QDir dir ( QDir::fromNativeSeparators(
               QCoreApplication::applicationDirPath() + "/data/cards" ) );
  dir.mkpath( "." );
  auto json = QJsonDocument( toJson( card ) );

  QFile f ( QDir::fromNativeSeparators(
              dir.absolutePath() + "/" + card->fio() + "_" + card->docSerial() + "_" + card->docNumber() ) );
  if ( f.open( QIODevice::WriteOnly ) ) {
    f.write( json.toJson( ) );
    f.close();
    return true;
  }

  return false;
}


IMedicalCard *MedicalCardProvider::create() const
{
  return new MedicalCard();
}

QList<IMedicalCard *> MedicalCardProvider::loadAll() const
{
  QDir dir ( QDir::fromNativeSeparators(
               QCoreApplication::applicationDirPath() + "/data/cards" ) );
  dir.mkpath( "." );

  QList<IMedicalCard *> cards;
  for ( auto &name: dir.entryList( QDir::Files ) ) {
    auto card = mediacalCardFromFile( dir.absoluteFilePath( name ) );
    if ( card )
      cards << card;
  }

  return cards;
}

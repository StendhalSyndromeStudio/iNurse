#include "property_provider.h"

#include "property/snils_property.h"
#include "property/regexp_property.h"
Q_DECLARE_METATYPE(QStringList)
PropertyProvider::PropertyProvider()
{
  add( "regexp", [](const QString &id)->IProperty* {
    return new RegExpProperty( id );
  } );

  add( "snils", [](const QString &id)->IProperty* {
    return new SnilsProperty( id );
  } );
}

PropertyProvider::~PropertyProvider()
{

}

void PropertyProvider::add(const QString &type, const PropertyProvider::PropertyCreator &creator)
{
  creators[ type ] = creator;
}

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QCoreApplication>
#include "property/base_property.h"
IProperty *PropertyProvider::create(const QString &id, const QString &type)
{
  IProperty *prop = nullptr;

  if ( creators.contains( type ) ) {
    try {
      prop = creators[ type ]( id );
    } catch (...) {
    }
  }

  if ( !prop )
    prop = new BaseProperty( id, type );

  QDir dir ( QDir::fromNativeSeparators(
               QCoreApplication::applicationDirPath() + "/data/types" ) );
  dir.mkpath( "." );

  QFile f ( QDir::fromNativeSeparators( dir.absolutePath() + "/" + type + ".json" ) );
  if ( f.open( QIODevice::ReadOnly ) ) {
    auto obj = QJsonDocument::fromJson( f.readAll() ).object();
    f.close();

    for ( auto &key: obj.keys() ) {
      auto item = obj[ key ];
      if ( item.isArray() ) {
        QStringList list;
        auto arr = item.toArray();
        for ( int i = 0; i < arr.count(); ++i ) {
            auto text = arr.at( i ).toString();
            if ( !text.isEmpty() )
              list << text;
        }

        prop->setById( key, QVariant::fromValue( list ) );
      } else if ( item.isString() ) {
        prop->setById( key, item.toString() );
      }
    }
  } else {
    qDebug() << "error load property: " << type << f.errorString() << f.fileName();
  }

  return prop;
}

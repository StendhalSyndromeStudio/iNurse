#include "assistant.h"

#include <texttospeech.h>
#include <impl/medical_card_provider.h>

#include "task/form_assistant.h"
Assistent::Assistent(QObject *parent)
  : QObject(parent)
  , proxy ( new VoiceProxy( 6790, QUrl( "ws://127.0.0.1:6789" ), true ) )
  , storage ( new AssistantTaskStorage() )
  , card ( nullptr )
{
  auto speach = TextToSpeech::instanse();
  connect( speach,    &TextToSpeech::EndPlay,
           [this]() {
    proxy->setRecognitionActive( true );
  });

  connect( proxy,   &VoiceProxy::recognized,
           [this](const QJsonObject &obj){
    if ( obj[ "final" ].toBool() ) {
      auto array = obj[ "alternatives" ].toArray();
      QStringList altr;
      for ( int i = 0; i < array.count(); ++i ) {
        altr << array.at( i ).toString();
      }
      storage->recognition( altr );
    } else {
      qDebug() << "wait";
    }
  });

  connect( storage, &AssistantTaskStorage::query,
           [this](const QString &data){ this->say( data ); });

  storage->addChildTask<FormAssistant>( &mw );
  forms = MedicalCardProvider().loadAll();

  proxy->setRecognitionActive( true );

  QTimer::singleShot( 500, [this]() {
    mw.show();
//    storage->recognition( { "Создать карту" } );
  });

//  say( "Хер с горы. Хер с горы. Хер с горы. Хер с горы. Хер с горы. Хер с горы. Хер с горы. Хер с горы." );

}

Assistent::~Assistent()
{

}

void Assistent::saveCard()
{
  if ( card ) {
    if ( MedicalCardProvider().save( card ) ) {
      say( "Сохранено" );
    } else {
      say( "Во время сохранения произошла ошибка" );
    }
  }
}

void Assistent::closeCard()
{
  if ( mw.closeCurrentForm() ) {
    say( "Форма закрыта" );
  } else {
    say( "Нет активных форм" );
  }
}

void Assistent::createCard()
{
  say( tr ( "Создаю новую медкарту" ) );
  card = MedicalCardProvider().create();
  mw.openForm( card );
}

void Assistent::openCard(IMedicalCard *card)
{
  say( tr ( "Открываю новую медкарту" ) );
  this->card = card;
  mw.openForm( card );
}

Assistent *Assistent::inst()
{
  static Assistent *instance = nullptr;
  if ( !instance )
    instance = new Assistent();

  return instance;
}

void Assistent::say(const QString &text)
{
  if ( proxy->isRecognitionActive() ) {
    proxy->setRecognitionActive( false );
    TextToSpeech::instanse()->AddPlay( text );
  }
}

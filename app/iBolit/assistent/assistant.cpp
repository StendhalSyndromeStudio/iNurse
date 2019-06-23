#include "assistant.h"

#include <texttospeech.h>

Assistent::Assistent(QObject *parent)
  : QObject(parent)
  , proxy ( new VoiceProxy( 6790, QUrl( "ws://127.0.0.1:6789" ), true ) )
  , storage ( new AssistantTaskStorage() )
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
    }
  });

  connect( storage, &AssistantTaskStorage::query,
           [this](const QString &data){ this->say( data ); });

  proxy->setRecognitionActive( true );
}

Assistent::~Assistent()
{

}

Assistent *Assistent::inst()
{
  static Assistent *instance;
  if ( !instance )
    instance = new Assistent();

  return instance;
}

void Assistent::say(const QString &text)
{
  proxy->setRecognitionActive( false );
  TextToSpeech::instanse()->AddPlay( text );
}

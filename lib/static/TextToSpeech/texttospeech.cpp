#include "texttospeech.h"

TextToSpeech*  TextToSpeech::singlenton =0;

TextToSpeech* TextToSpeech::instanse(QObject *parent){
    if (singlenton==0){
        singlenton = new TextToSpeech(parent);
    }
    return singlenton;
}

TextToSpeech::TextToSpeech(QObject *parent)
{
    TestVoice = new QTextToSpeech(parent);
    ListRecord = new QList<QString>();
    connect(TestVoice,&QTextToSpeech::stateChanged,this,&TextToSpeech::StopSpeech);
    connect(&TimerPlay,&QTimer::timeout,this,&TextToSpeech::UpdateTimer);
    TimerPlay.setInterval(500);
    TimerPlay.start();
}


void TextToSpeech::AddPlay(QString value){
   ListRecord->append(value);
}

void TextToSpeech::StopPlay(){
    TestVoice->stop();
    ListRecord->clear();
    BlocingNewPlay = false;
}

void TextToSpeech::StopSpeech(QTextToSpeech::State value){
    if (value == QTextToSpeech::State::Ready){
        if (ListRecord->count()!=0){
            emit EndPlay(ListRecord->at(0));
            ListRecord->removeAt(0);
        }
        else{
            emit EndPlay(CurrentText);
        }
        BlocingNewPlay = false;
    }
}

void TextToSpeech::UpdateTimer(){
    if (ListRecord->count()!=0 && BlocingNewPlay==false){
        TestVoice->say(ListRecord->at(0));
        CurrentText = ListRecord->at(0);
        BlocingNewPlay = true;
    }
}

#include "form_assistant.h"
#include "assistent/assistant.h"
#include "assistent/check_true_pattern.h"

static QStringList FormAssistantCreateList  = QStringList {
    "Создать карту", "Создать карту", "Создать Медкарту" };

static QStringList FormAssistantOpenList    = QStringList {
    "Выбрать карту", "Открыть карту", "Медкарта", "Мед карта" };

static QStringList FormAssistantCloseList    = QStringList {
    "Закрыть форму", "Закрыть" };

static QStringList FormAssistantSaveList    = QStringList {
    "Сохранить форму", "Сохранить", "Сохранить изменения" };


FormAssistant::FormAssistant(MainWindow *mw)
  : AssistantQueryTask()
  , mw ( mw )
{

}

FormAssistant::~FormAssistant()
{

}

QStringList FormAssistant::activateCommand() const
{
  auto list = FormAssistantOpenList;
  list.append( FormAssistantCreateList );
  list.append( FormAssistantSaveList );
  list.append( FormAssistantCloseList );
  return list;
}

void FormAssistant::reply(const QString &question, const QStringList &reply)
{

  if ( question.isEmpty() ) {
    if ( CheckTruePattern::check( reply, FormAssistantCreateList ) ) {
      Assistent::inst()->createCard();
    }

    // Close form
    else if ( CheckTruePattern::check(  reply, FormAssistantCloseList ) ) {
      auto closeForm = []() {
        Assistent::inst()->closeCard();
      };

      auto saveForm = []() {
          Assistent::inst()->saveCard();
          Assistent::inst()->closeCard();
      };

      sendQuery( "Вы в этом уверены?", [this, closeForm, saveForm](const QStringList &pattern) {
        if ( CheckTruePattern::check( pattern ) ) {
          sendQuery( "Сохранить перед закрытием?", [closeForm, saveForm](const QStringList &pattern) {
            if ( CheckTruePattern::check( pattern ) )
              saveForm();

            closeForm();
          } );
        }

      } );
    }

    // Save form
    else if ( CheckTruePattern::check(  reply, FormAssistantSaveList ) ) {
      Assistent::inst()->saveCard();
    }

    // Open Form
    else if ( CheckTruePattern::check(  reply, FormAssistantOpenList ) ) {
      sendQuery( "Карту какого пациента необходимо загрузить?",
                 [this](const QStringList &tmp) {
        IMedicalCard *current = nullptr;
        int maxValue = 0;
        for ( auto &card: Assistent::inst()->forms ) {
          int maxPattern = 0;
          for  ( auto pattern: tmp ) {
              int count = 0;
              for ( auto &name: pattern.toLower().split( " " ) ) {
                if ( card->fio().toLower().indexOf( name ) != -1 )
                  ++count;
              }
              maxPattern = std::max ( maxPattern, count );
            }

          if ( maxValue < maxPattern && maxPattern > 1 ) {
            maxValue = maxPattern;
            current  = card;
          }
        }

        if ( current ) {
          this->sendQuery( "Открыть карту " + current->fio() + "?", [current](const QStringList &pattern) {
            if ( CheckTruePattern::check( pattern ) ) {
              Assistent::inst()->openCard( current );
              return ;
            }
          });
        } else if ( tmp.isEmpty() ) {
            this->sendQuery( "Нехотите не отвечайте." , [](const QStringList &){} );
        } else {
          this->sendQuery( "Пользователь не найден, создать новую карту?" , [](const QStringList &pattern){
            if ( CheckTruePattern::check( pattern ) )
              Assistent::inst()->createCard();
          } );
        }
      });
    }

  } else {
    AssistantQueryTask::reply( question, reply );
  }
}

#ifndef TEXTTOSPEECH_H
#define TEXTTOSPEECH_H
#include <QtTextToSpeech>
#include <QTimer>


class TextToSpeech: public QObject
{
 Q_OBJECT


public:
    /**
     * @brief instanse - ПРИ ПЕРВОМ ИСПОЛЬЗОВАНИИ ПЕРЕДАЧА Qobject ОБЯЗАТЕЛЬНА
     * @param parent - ПРИ ПЕРВОМ ИСПОЛЬЗОВАНИИ ПЕРЕДАЧА Qobject ОБЯЗАТЕЛЬНА
     * @return преобразование текста в речь
     */
    static TextToSpeech* instanse(QObject *parent= nullptr);

private:
    /**
     * @brief singlenton объект синглентона
     */
    static TextToSpeech* singlenton;
    /**
     * @brief TextToSpeech конструктор класса
     * @param parent родительский объект ОБЯЗАТЕЛЬНО
     */
    TextToSpeech(QObject *parent);
    QTextToSpeech* TestVoice;
     /**
      * @brief ListRecord - хранилище записей на воспроизведение
      */
     QList<QString>* ListRecord = nullptr;
     /**
      * @brief TimerPlay таймер проигрывания множественных записей
      */
     QTimer TimerPlay;
     /**
      * @brief BlocingNewPlay блокирует проигрывание записи
      */
     bool BlocingNewPlay=false;
     /**
      * @brief CurrentText текущий текст проигрывания
      */
     QString CurrentText;
signals:
     /**
      * @brief EndPlay - сигнал что воспроизведение текста закончилось
      * @param value - текст по которому закончилось воспроизведение
      */
     void EndPlay(QString value);

public slots:
     /**
      * @brief AddPlay добавление текстовой подписи на воспроизведение
      * @param value текстовая строка
      */
     void AddPlay(QString value);
     /**
      * @brief StopPlay полная остановка проигрывания
      */
     void StopPlay();

private slots:
     /**
      * @brief StopSpeech принимает сигнал от синтезатора о заканчивании проговора текущего предложения
      */
     void StopSpeech(QTextToSpeech::State value);
     /**
      * @brief UpdateTimer - обновление таймера
      */
     void UpdateTimer();
};

#endif // TEXTTOSPEECH_H

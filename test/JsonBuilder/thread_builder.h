#ifndef THREAD_WRITER_H
#define THREAD_WRITER_H

#include <atomic>
#include <QThread>

class JsonBuilderMw;
class ThreadBuilder
    : public QThread
{
  Q_OBJECT
  JsonBuilderMw *mw;
  std::atomic_bool  runing, aborting;
  QString in, out;
  QStringList fields;
public:
  explicit ThreadBuilder(JsonBuilderMw *mw);
  ~ThreadBuilder() override;

public:
  bool isWork() const;

public slots:
  void start(const QString &in, const QString &out, const QStringList &fields);
  void abort();

  // QThread interface
protected:
  void run() override;
};

#endif // THREAD_WRITER_H

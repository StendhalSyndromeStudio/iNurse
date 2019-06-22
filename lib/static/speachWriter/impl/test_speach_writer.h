#ifndef TEST_SPEACH_WRITER_H
#define TEST_SPEACH_WRITER_H

#include "interfaces/ispeach_writer.h"

class TestSpeachWriter final
    : public ISpeachWriter
{
  Q_OBJECT
  IPropertyForm     *object;
  IProperty         *current;
  QList<IProperty*> _properties;
public:
  explicit TestSpeachWriter();
  virtual ~TestSpeachWriter() override;

private slots:
  void clearProperty();
  void activatedProperty();
  void deactivatedProperty();

  // IVoiceObject interface
public:
  virtual bool hasWaitData() const override;

public slots:
  virtual void recognition(const QString &data) override;

private slots:
  void connectForm(IPropertyForm *form);
  void disconnectForm(IPropertyForm *form);
  void connectPropery(IProperty *property) ;
  void disconnectPropery(IProperty *property) ;

  // ISpeachWriter interface
public:
  virtual IPropertyForm *form() const override;
  virtual QList<IProperty *> properties() const override;

public slots:
  virtual void setPropertyObj(IPropertyForm *form) override;
};

#endif // TEST_SPEACH_WRITER_H

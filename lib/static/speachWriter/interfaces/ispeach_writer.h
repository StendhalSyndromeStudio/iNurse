#ifndef ISPEACHWRITER_H
#define ISPEACHWRITER_H

#include <QObject>
#include "ivoice_object.h"

class IProperty;
class IPropertyForm;
class ISpeachWriter
    : public IVoiceObject
{
  Q_OBJECT
protected:
  ISpeachWriter();
public:
  virtual ~ISpeachWriter() override;

public:
  virtual IPropertyForm *form() const = 0;
  virtual QList<IProperty*> properties() const = 0;

public slots:
  virtual void setPropertyObj(IPropertyForm *form) = 0;

signals:
  void changed();
};

#endif // ISPEACHWRITER_H

#ifndef ISPEACHWRITER_H
#define ISPEACHWRITER_H

#include <QObject>
#include "ivoice_object.h"

class IProperty;
class ISpeachWriter
    : public IVoiceObject
{
  Q_OBJECT
protected:
  ISpeachWriter();
public:
  virtual ~ISpeachWriter() override;

public:
  virtual IPropertyObject *obj() const = 0;
  virtual QList<IProperty*> properties() const = 0;

public slots:
  virtual void setPropertyObj(IPropertyObject *obj) = 0;

signals:
  void changed();
};

#endif // ISPEACHWRITER_H

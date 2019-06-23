#ifndef IMEDICAL_CARD_H
#define IMEDICAL_CARD_H

#include "iproperty_form.h"

class IMedicalCard
    : public IPropertyForm
{
  Q_OBJECT
protected:
  explicit IMedicalCard();
public:
  ~IMedicalCard() override;

public:
  virtual QList<IPropertyForm*> forms() const = 0;

public:
  virtual QString fio() const = 0;
  virtual QString dataBirth() const = 0;
  virtual QString docSerial() const = 0;
  virtual QString docNumber() const = 0;

public slots:
  virtual void add(IPropertyForm *form) = 0;
  virtual void remove(IPropertyForm *form) = 0;

signals:
  void added(IPropertyForm *form);
  void removed(IPropertyForm *form);
};

#endif // IMEDICAL_CARD_H

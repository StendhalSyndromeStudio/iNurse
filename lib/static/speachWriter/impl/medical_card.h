#ifndef MEDICAL_CARD_H
#define MEDICAL_CARD_H

#include <interfaces/imedical_card.h>
#include "property_form.h"

class MedicalCard
    : public IMedicalCard
{
  Q_OBJECT
  PropertyForm          *form;
  QList<IPropertyForm*> childForms;
public:
  explicit MedicalCard();
  ~MedicalCard() override;

public :
  QVariant getValue(const QString &id) const;

  // IPropertyForm interface
public:
  virtual QString id() const override;
  virtual QString type() const override;
  virtual QString name() const override;
  virtual QString description() const override;
  virtual QList<IProperty *> properties() const override;
  virtual IProperty *property(const QString &id, const QString &type) override;

  // IMedicalCard interface
public:
  virtual QList<IPropertyForm *> forms() const override;
  virtual QString fio() const override;
  virtual QString dataBirth() const override;
  virtual QString docSerial() const override;
  virtual QString docNumber() const override;

public slots:
  virtual void add(IPropertyForm *form) override;
  virtual void remove(IPropertyForm *form) override;
};

#endif // MEDICAL_CARD_H

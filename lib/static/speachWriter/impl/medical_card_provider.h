#ifndef MEDICAL_CARD_PROVIDER_H
#define MEDICAL_CARD_PROVIDER_H

#include "interfaces/imedica_card_provider.h"

class MedicalCardProvider final
    : public IMedicalCardProvider
{
public:
  MedicalCardProvider();
  ~MedicalCardProvider() override;

  // IMedicalCardProvider interface
public:
  virtual bool save(IMedicalCard *card) const override;
  virtual IMedicalCard *create() const override;
  virtual QList<IMedicalCard *> loadAll() const override;
};

#endif // MEDICAL_CARD_PROVIDER_H

#ifndef IMEDICA_CARD_PROVIDER_H
#define IMEDICA_CARD_PROVIDER_H

#include <QList>

class IMedicalCard;
class IMedicalCardProvider
{
protected:
  IMedicalCardProvider();
public:
  virtual ~IMedicalCardProvider();

public:
  virtual bool save(IMedicalCard *card) const = 0;
  virtual IMedicalCard *create() const = 0;
  virtual QList<IMedicalCard *> loadAll() const = 0;
};

#endif // IMEDICA_CARD_PROVIDER_H

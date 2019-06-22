#ifndef REGEXP_PROPERTY_H
#define REGEXP_PROPERTY_H

#include <QRegExp>
#include "base_property.h"

class RegExpProperty
    : public BaseProperty
{
  Q_OBJECT
protected:
  QStringList   _patterns;
public:
  explicit RegExpProperty(const QString &id
                          , const QString &type = "regExp"
                          , const QVariant &value = ""
                          , const QStringList patterns = QStringList() );
  virtual ~RegExpProperty() override;

public:
  QStringList patterns() const;

public slots:
  void setPattern(const QString &pattern);
  void setPattern(const QStringList &patterns);
  void addPattern(const QString &pattern);
  void removedPattern(const QString &pattern);

protected:
  virtual bool validate(const QString &data) const;
  virtual bool validate(const QString &pattern, const QString &data) const;
  virtual bool validate(const QStringList &patternList, const QString &data) const;

  // IVoiceObject interface

public slots:
  virtual void recognition(const QString &data) override;
};

#endif // REGEXP_PROPERTY_H

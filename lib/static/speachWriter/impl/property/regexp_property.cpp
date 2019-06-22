#include "regexp_property.h"
#include <QRegExpValidator>

RegExpProperty::RegExpProperty(const QString &id, const QString &type, const QVariant &value, const QStringList patterns)
  : BaseProperty( id, type, value )
  , _patterns ( patterns )
{

}

RegExpProperty::~RegExpProperty()
{

}

QStringList RegExpProperty::patterns() const
{
  return _patterns;
}

void RegExpProperty::setPattern(const QString &pattern)
{
  _patterns = QStringList{ pattern };
}

void RegExpProperty::setPattern(const QStringList &patterns)
{
  _patterns = patterns;
}

void RegExpProperty::addPattern(const QString &pattern)
{
  if ( !_patterns.contains( pattern ) )
    _patterns << pattern;
}

void RegExpProperty::removedPattern(const QString &pattern)
{
  _patterns.removeOne( pattern );
}

bool RegExpProperty::validate(const QString &data) const
{
  return validate( _patterns, data );
}

bool RegExpProperty::validate(const QString &pattern, const QString &data) const
{
  QRegExp exp ( pattern );
  QRegExpValidator validator( exp );
  int pos;
  QString tmp = data;
  if ( validator.validate( tmp, pos ) == QValidator::State::Acceptable ) {
    return true;
  }

  return false;
}

bool RegExpProperty::validate(const QStringList &patternList, const QString &data) const
{
  for ( auto &p: patternList )
    if ( validate( p, data ) )
      return true;
  return false;
}

void RegExpProperty::recognition(const QString &data)
{
  if ( validate( data ) ) {
    setValue( data );
  }
}

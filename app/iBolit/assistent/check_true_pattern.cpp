#include "check_true_pattern.h"

bool CheckTruePattern::check(const QStringList &pattern)
{
  for  ( auto &p: pattern ) {
    for ( auto &ok: QStringList{ "да", "конечно", "давай", "быстрее" } ) {
      if ( p.toLower().indexOf( ok ) != -1 ) {
        return true;
      }
    }
  }
  return false;
}

bool CheckTruePattern::check(const QStringList &activateList, const QStringList &pattern)
{
  double itemMax = 0.0;
  for ( auto &activ: pattern ) {
    for ( auto &r: activateList ) {
      int pos = activ.trimmed().toLower().indexOf( r.trimmed().toLower() );
      if ( pos >= 0 ) {
        itemMax = std::max ( itemMax, static_cast<double>( r.length() ) / activ.length() );
      }
    }

    if ( itemMax >= 0.5 ) {
      return true;
    }

  }
  return false;
}

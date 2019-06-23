#ifndef CHECK_TRUE_PATTERN_H
#define CHECK_TRUE_PATTERN_H

#include <QObject>

class CheckTruePattern
{
    CheckTruePattern() = delete;
public:
  static bool check(const QStringList &pattern);
  static bool check(const QStringList &activateList, const QStringList &pattern);
};

#endif // CHECK_TRUE_PATTERN_H

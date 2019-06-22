#include <QtTest>
#include <QDateTime>
#include <QCoreApplication>
#include <impl/property/regexp_property.h>

// add necessary includes here

class SpeachWriterPropertyTest : public QObject
{
  Q_OBJECT

public:
  SpeachWriterPropertyTest();
  ~SpeachWriterPropertyTest();

public:
  QString generateSnils() const;
  bool testSnils(const QString &snils);

private slots:
  void initTestCase();
  void cleanupTestCase();
  void test_case1();
  void test_case2();
  void test_case3();

};

SpeachWriterPropertyTest::SpeachWriterPropertyTest()
{

}

SpeachWriterPropertyTest::~SpeachWriterPropertyTest()
{

}

QString SpeachWriterPropertyTest::generateSnils() const
{
  int v1 = std::rand() % 10
      , v2 = std::rand() % 10
      , v3 = std::rand() % 10
      , v4 = std::rand() % 10
      , v5 = std::rand() % 10
      , v6 = std::rand() % 10
      , v7 = std::rand() % 10
      , v8 = std::rand() % 10
      , v9 = std::rand() % 10;

  int crc = v1 * 1 + v2 * 2 + v3 * 3 + v4 * 4 + v5 * 5 + v6 * 6 + v7 * 7 + v8 * 8 + v9 * 9;

  switch ( std::rand() % 3 ) {
    case 0:
      return QString( "%1%2%3%4%5%6%7%8%9%10" )
          .arg( v1 )
          .arg( v2 )
          .arg( v3 )
          .arg( v4 )
          .arg( v5 )
          .arg( v6 )
          .arg( v7 )
          .arg( v8 )
          .arg( v9 )
          .arg( crc );
    case 1:
      return QString( "%1%2%3%4%5%6%7%8%9 %10" )
          .arg( v1 )
          .arg( v2 )
          .arg( v3 )
          .arg( v4 )
          .arg( v5 )
          .arg( v6 )
          .arg( v7 )
          .arg( v8 )
          .arg( v9 )
          .arg( crc );
    default:
      return QString( "%1%2%3-%4%5%6-%7%8%9 %10" )
          .arg( v1 )
          .arg( v2 )
          .arg( v3 )
          .arg( v4 )
          .arg( v5 )
          .arg( v6 )
          .arg( v7 )
          .arg( v8 )
          .arg( v9 )
          .arg( crc );
  }


}

#include <impl/property/snils_property.h>
bool SpeachWriterPropertyTest::testSnils(const QString &snils)
{
  auto obj = std::make_shared<SnilsProperty>( "test_snils" );
  obj->recognition( snils );
  return obj->value().toString() == snils;
}

void SpeachWriterPropertyTest::initTestCase()
{

}

void SpeachWriterPropertyTest::cleanupTestCase()
{

}

void SpeachWriterPropertyTest::test_case1()
{
  auto p = std::make_shared<RegExpProperty>( "test" );
  p->setPattern( "[0-9]{1,4}$" );

  p->recognition( "1234" );
  QVERIFY2( p->value().toString() == "1234", "Error set vaild value" );

  p->recognition( "test" );
  QVERIFY2( p->value().toString() != "test", "Error set invaild value" );



}

void SpeachWriterPropertyTest::test_case2()
{
  for ( int i = 0; i < 1; ++i ) {
    QVERIFY2( testSnils( generateSnils() ), "Error set valid snils" );
  }

  QVERIFY2( !testSnils( "0" ), "Error set invalid snils" );
  QVERIFY2( !testSnils( "1234" ), "Error set invalid snils" );
  QVERIFY2( !testSnils( "000 000 000 00" ), "Error set invalid snils" );
  QVERIFY2( !testSnils( "999-999999-00" ), "Error set invalid snils" );
  QVERIFY2( !testSnils( "000-000-000 00" ), "Error set invalid snils" );
}

#include "interfaces/ispeach_writer.h"
#include "impl/test_property_object.h"
#include "impl/speach_writer_provider.h"
void SpeachWriterPropertyTest::test_case3()
{
  auto obj    = new TestPropertyObject();
  auto writer = SpeachWriterProvider().create();

  writer->setPropertyObj( obj );

  auto dt = QDateTime::currentMSecsSinceEpoch();
  while ( QDateTime::currentMSecsSinceEpoch() - dt < 5000 ) {
    QCoreApplication::processEvents();
  }
}

QTEST_MAIN(SpeachWriterPropertyTest)

#include "tst_speachwriterpropertytest.moc"

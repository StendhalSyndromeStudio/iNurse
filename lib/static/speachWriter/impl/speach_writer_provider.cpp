#include "speach_writer_provider.h"

SpeachWriterProvider::SpeachWriterProvider()
{

}

SpeachWriterProvider::~SpeachWriterProvider()
{

}

#include "test_speach_writer.h"
ISpeachWriter *SpeachWriterProvider::create() const
{
  return new TestSpeachWriter();
}

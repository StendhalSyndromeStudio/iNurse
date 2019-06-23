#ifndef SPEACH_WRITER_CREATOR_H
#define SPEACH_WRITER_CREATOR_H

#include "interfaces/ispeach_writer_provider.h"

class SpeachWriterProvider
    : public ISpeachWriterProvider
{
public:
  SpeachWriterProvider();
  ~SpeachWriterProvider() override;

  // ISpeachWriterCreator interface
public:
  virtual ISpeachWriter *create() const override;
};

#endif // SPEACH_WRITER_CREATOR_H

#ifndef ISPEACH_WRITER_CREATOR_H
#define ISPEACH_WRITER_CREATOR_H


class ISpeachWriter;
class ISpeachWriterProvider
{
protected:
  ISpeachWriterProvider();
public:
  virtual ~ISpeachWriterProvider();

public:
  virtual ISpeachWriter *create() const = 0;
};

#endif // ISPEACH_WRITER_CREATOR_H

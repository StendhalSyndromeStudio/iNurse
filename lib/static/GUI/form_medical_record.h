#ifndef FORM_MEDICAL_RECORD_H
#define FORM_MEDICAL_RECORD_H

#include <QWidget>
#include "universal_gui_writer.h"
#include <interfaces/iproperty_widget.h>
#include <interfaces/iproperty_form.h>

namespace Ui {
  class FormMedicalRecord;
}

class FormMedicalRecord : public QWidget, public IPropertyWidget
{
  Q_OBJECT
  Ui::FormMedicalRecord *ui;
  UniversalGuiWriter *writer;
public:
  explicit FormMedicalRecord(QWidget *parent = nullptr);
  ~FormMedicalRecord();

  static int GUID() { return ++_guid; }

  // IPropertyWidget interface
public:
  virtual QString type() const override;
  virtual void reload() override;
  virtual void initilize(IPropertyForm *form) override;

  void print();

private:
  static int _guid;
};

#endif // FORM_MEDICAL_RECORD_H

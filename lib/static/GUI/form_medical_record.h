#ifndef FORM_MEDICAL_RECORD_H
#define FORM_MEDICAL_RECORD_H

#include <QWidget>
#include "universal_gui_writer.h"
#include <interfaces/Iproperty_object.h>

namespace Ui {
class FormMedicalRecord;
}

class FormMedicalRecord : public QWidget, public IPropertyObject
{
    Q_OBJECT
  Ui::FormMedicalRecord *ui;
  UniversalGuiWriter *writer;
public:
    explicit FormMedicalRecord(QWidget *parent = nullptr);
    ~FormMedicalRecord();

    // IPropertyObject interface
    ItemList items() const;
    bool setItem(const Item &item, const QString &text);


};

#endif // FORM_MEDICAL_RECORD_H

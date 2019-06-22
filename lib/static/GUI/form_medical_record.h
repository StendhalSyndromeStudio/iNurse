#ifndef FORM_MEDICAL_RECORD_H
#define FORM_MEDICAL_RECORD_H

#include <QWidget>
#include <interfaces/Iproperty_object.h>

namespace Ui {
class FormMedicalRecord;
}

class FormMedicalRecord : public QWidget, public IPropertyObject
{
    Q_OBJECT

public:
    explicit FormMedicalRecord(QWidget *parent = nullptr);
    ~FormMedicalRecord();

    // IPropertyObject interface
    ItemList items() const;
    bool setItem(const Item &item, const QString &text);


private:
    Ui::FormMedicalRecord *ui;


private:
    //Item addElement( QString id, QObject )
};

#endif // FORM_MEDICAL_RECORD_H

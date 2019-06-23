#ifndef FORM_RECIPE_H
#define FORM_RECIPE_H

#include <QWidget>
#include "universal_gui_writer.h"
#include <interfaces/iproperty_widget.h>
#include <interfaces/iproperty_form.h>

namespace Ui {
class FormRecipe;
}

class FormRecipe : public QWidget, public IPropertyWidget
{
    Q_OBJECT

public:
    explicit FormRecipe(QWidget *parent = nullptr);
    ~FormRecipe();

private:
    Ui::FormRecipe *ui;

    // IPropertyWidget interface
public:
    QString type() const;
    void reload();
    void initilize(IPropertyForm *form);
};

#endif // FORM_RECIPE_H

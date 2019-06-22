#ifndef FORM_RECIPE_H
#define FORM_RECIPE_H

#include <QWidget>

namespace Ui {
class FormRecipe;
}

class FormRecipe : public QWidget
{
    Q_OBJECT

public:
    explicit FormRecipe(QWidget *parent = nullptr);
    ~FormRecipe();

private:
    Ui::FormRecipe *ui;
};

#endif // FORM_RECIPE_H

#include "form_recipe.h"
#include "ui_form_recipe.h"

FormRecipe::FormRecipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRecipe)
{
    ui->setupUi(this);
}

FormRecipe::~FormRecipe()
{
    delete ui;
}

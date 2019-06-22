#ifndef FORM_DIRECTION_H
#define FORM_DIRECTION_H

#include <QWidget>

namespace Ui {
class FormDirection;
}

class FormDirection : public QWidget
{
    Q_OBJECT

public:
    explicit FormDirection(QWidget *parent = nullptr);
    ~FormDirection();

private:
    Ui::FormDirection *ui;
};

#endif // FORM_DIRECTION_H

#ifndef FORMPROGRESS_H
#define FORMPROGRESS_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class FormProgress;
}

class FormProgress : public QWidget
{
    Q_OBJECT

public:
    explicit FormProgress(QWidget *parent = nullptr);
    ~FormProgress();
    void SetForm(QWidget* widget);

private slots:
    void Ontimer();

private:
    Ui::FormProgress *ui;
    QTimer TimeProgress;
    QWidget *widget;
};

#endif // FORMPROGRESS_H

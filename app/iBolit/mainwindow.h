#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMap>
#include <QMdiArea>
#include <QMainWindow>
#include <interfaces/iproperty_form.h>
#include <interfaces/Iproperty_widget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
  IPropertyForm *current;
  QMap<IPropertyForm*, IPropertyWidget*> _openedForms;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
  IPropertyForm *currentForm() const;
  QList<IPropertyForm *> openedForms() const;
  bool contains(IPropertyForm *form) const;

public slots:
  bool openForm(IPropertyForm *form);
  bool closeForm(IPropertyForm *form);
  bool closeCurrentForm();
  bool setCurrentForm(IPropertyForm *form);


private slots:
    void on_action_quit_triggered();

    void on_action_add_doc_triggered();

    void changePatcient();

private:
    Ui::MainWindow *ui;

    QMdiArea* _area;

};

#endif // MAINWINDOW_H

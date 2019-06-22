#ifndef MAINWINDOWUI_H
#define MAINWINDOWUI_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMap>

namespace Ui {
class MainWindowUI;
}

class MainWindowUI : public QMainWindow
{
    Q_OBJECT

public:

    enum class CodeWindow {
        medical_record,
        visit_doctor,
        direction,
        recipe
    };

    explicit MainWindowUI(QWidget *parent = nullptr);
    ~MainWindowUI();

private:
    Ui::MainWindowUI *ui;

    QMdiArea* _area;

private:
    void createWindow( CodeWindow code );
};

#endif // MAINWINDOWUI_H

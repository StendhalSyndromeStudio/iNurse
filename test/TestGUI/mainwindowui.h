#ifndef MAINWINDOWUI_H
#define MAINWINDOWUI_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMap>
#include <gui.h>

namespace Ui {
class MainWindowUI;
}

class MainWindowUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowUI(QWidget *parent = nullptr);
    ~MainWindowUI();

private:
    Ui::MainWindowUI *ui;

    QMdiArea* _area;

private:
    void createWindow( GUI::CodeWindow code );
};

#endif // MAINWINDOWUI_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "processor.h"



namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void refreshFetch();
    void refreshDeco();
    void refreshExe();
    void refreshWriteBack();

    void setProcessor(Processor* processor);
private slots:


    void on_boton_paso_clicked();

    void on_ejecutar_all_clicked();

private:
    Ui::MainWindow *ui;
    Processor* processor;
};

#endif // MAINWINDOW_H

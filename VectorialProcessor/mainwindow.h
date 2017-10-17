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
    void refreshFetch(int pc);
    void refreshDeco(int ra, int rb , int dir_C, int content_ra, int content_rb, int con_RA, int conRB);

    void setProcessor(Processor* processor);
private slots:


    void on_boton_paso_clicked();

    void on_ejecutar_all_clicked();

private:
    Ui::MainWindow *ui;
    Processor* processor;
};

#endif // MAINWINDOW_H

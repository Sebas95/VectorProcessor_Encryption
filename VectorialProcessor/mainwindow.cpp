#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);




}


void MainWindow::refreshFetch(int pc)
{
    QString s_pc = QString::number(pc);

    ui->pc_boton->setText(s_pc);
}

void  MainWindow::refreshDeco(int ra, int rb , int dir_C, int content_ra, int content_rb, int con_RA, int conRB)
{

    ui->boton_ra->setText(QString::number(ra));
    ui->boton_rb->setText(QString::number(rb));
    ui->boton_RA->setText(QString::number(ra));
    ui->Boton_RB->setText(QString::number(rb));
    ui->boton_dirc1->setText(QString::number(dir_C));
    ui->boton_dirc2->setText(QString::number(dir_C));
    ui->boton_content_ra->setText(QString::number(content_ra));
    ui->boton_content_rb->setText(QString::number(content_rb));
    ui->boton_content_RA->setText(QString::number(con_RA));
    ui->boton_Content_RB->setText(QString::number(conRB));
    //QString s_ra = ;
    //QString s_rb = QString::number(rb);
    //QString s_dirc = QString::number(dir_C);
    //QString s_DinC1 = QString::number(DinC1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_boton_paso_clicked()
{

}

void MainWindow::on_ejecutar_all_clicked()
{
    pthread_t p;
    int* g;
    pthread_create(&p,NULL,executeInstructions,(void*)g);
}

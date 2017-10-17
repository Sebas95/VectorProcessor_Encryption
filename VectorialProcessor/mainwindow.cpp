#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);




}


void MainWindow::refreshFetch()
{
    QString s_pc = QString::number(processor->pc);

    ui->pc_boton->setText("pc: "+s_pc);
}

void  MainWindow::refreshDeco()
{

    ui->imm_deco->setText("imm :"+ QString::number(*processor->immExt));
    ui->boton_ra->setText("ra: "+QString::number(processor->converter->convert(processor->ra,2)));
    ui->boton_rb->setText("rb: "+QString::number(processor->converter->convert(processor->rb,2)));
    ui->boton_RA->setText("RA: "+QString::number(processor->converter->convert(processor->ra,2)));
    ui->Boton_RB->setText("RB: "+QString::number(processor->converter->convert(processor->rb,2)));
    //ui->boton_dirc1->setText(QString::number(processor->pipe_d_e->dir_rc));
    //ui->boton_dirc2->setText(QString::number(dir_C));
    bool* dc =new bool[2]();
    processor->pipe_f_d->getRc(dc);
    ui->boton_dirc_fetch->setText("rc: "+QString::number(processor->converter->convert(dc,2)));
    ui->boton_content_ra->setText("ra: "+QString::number(*(int*)processor->content_ra));
    ui->boton_content_rb->setText("rb: "+QString::number(*(int*)processor->content_rb));

    unsigned char* Ra = processor->content_Ra;
    unsigned char* Rb = processor->content_Rb;
    QString string1 = "["+QString::number( (int)Ra[0])+","+QString::number( (int)Ra[1])+","+QString::number( (int)Ra[2])
            +","+QString::number( (int)Ra[3])+","+QString::number( (int)Ra[4])+","+QString::number( (int)Ra[5])
            +","+QString::number( (int)Ra[6])+","+QString::number( (int)Ra[7]) +"]";

    QString string2 = "["+QString::number( (int)Rb[0])+","+QString::number( (int)Rb[1])+","+QString::number( (int)Rb[2])
            +","+QString::number( (int)Rb[3])+","+QString::number( (int)Rb[4])+","+QString::number( (int)Rb[5])
            +","+QString::number( (int)Rb[6])+","+QString::number( (int)Rb[7]) +"]";


    ui->label_VA->setText("VA: " +string1);
    ui->label_VB->setText("VB: " +string2);
    //QString s_ra = ;
    //QString s_rb = QString::number(rb);
    //QString s_dirc = QString::number(dir_C);
    //QString s_DinC1 = QString::number(DinC1);
}


void  MainWindow::refreshExe()
{


    ui->dir_c_exe->setText("rc: "+QString::number(processor->pipe_d_e->dir_rc));
    ui->boton_ra_exe->setText("ra: "+QString::number(*(int*)processor->pipe_d_e->ra));
    ui->boton_rb_exe_->setText("rb: "+QString::number(*(int*)processor->pipe_d_e->rb));
    ui->imm_exe->setText("imm: "+QString::number(*(int*)processor->pipe_d_e->imm));
    ui->boton_salida_muxb->setText(QString::number(*(int*)processor->muxbResult));

    ui->pushButton_52->setText(QString::number(*(int*)processor->pipe_d_e->rb));
    ui->boton_resAlu32->setText(QString::number(*(int*)processor->aluResult32));
    ui->boton_dout32->setText(QString::number(*(unsigned int*)processor->memOut32));

    unsigned char* Ra = processor->pipe_d_e->Ra;
    unsigned char* Rb = processor->pipe_d_e->Rb;
    unsigned char* muxBig = processor->muxAResult;
    unsigned char* RepS = processor->replicatedScalar;
    unsigned char* AluRV = processor->aluResult64;
    unsigned char* Dout64 = processor->memOut64;
    QString string1 = "["+QString::number( (int)Ra[0])+","+QString::number( (int)Ra[1])+","+QString::number( (int)Ra[2])
            +","+QString::number( (int)Ra[3])+","+QString::number( (int)Ra[4])+","+QString::number( (int)Ra[5])
            +","+QString::number( (int)Ra[6])+","+QString::number( (int)Ra[7]) +" ]";

    QString string2 = "["+QString::number( (int)Rb[0])+","+QString::number( (int)Rb[1])+","+QString::number( (int)Rb[2])
            +","+QString::number( (int)Rb[3])+","+QString::number( (int)Rb[4])+","+QString::number( (int)Rb[5])
            +","+QString::number( (int)Rb[6])+","+QString::number( (int)Rb[7]) +" ]";

    QString string3 = "["+QString::number( (int)muxBig[0])+","+QString::number( (int)muxBig[1])+","+QString::number( (int)muxBig[2])
            +","+QString::number( (int)muxBig[3])+","+QString::number( (int)muxBig[4])+","+QString::number( (int)muxBig[5])
            +","+QString::number( (int)muxBig[6])+","+QString::number( (int)muxBig[7]) +"]";

    QString string4 = "["+QString::number( (int)RepS[0])+","+QString::number( (int)RepS[1])+","+QString::number( (int)RepS[2])
            +","+QString::number( (int)RepS[3])+","+QString::number( (int)RepS[4])+","+QString::number( (int)RepS[5])
            +","+QString::number( (int)RepS[6])+","+QString::number( (int)RepS[7]) +"]";

    QString string5 = "["+QString::number( (int)AluRV[0])+","+QString::number( (int)AluRV[1])+","+QString::number( (int)AluRV[2])
            +","+QString::number( (int)AluRV[3])+","+QString::number( (int)AluRV[4])+","+QString::number( (int)AluRV[5])
            +","+QString::number( (int)AluRV[6])+","+QString::number( (int)AluRV[7]) +"]";

    QString string6 = "["+QString::number( (int)Dout64[0])+","+QString::number( (int)Dout64[1])+","+QString::number( (int)Dout64[2])
            +","+QString::number( (int)Dout64[3])+","+QString::number( (int)Dout64[4])+","+QString::number( (int)Dout64[5])
            +","+QString::number( (int)Dout64[6])+","+QString::number( (int)Dout64[7]) +"]";

    ui->label_VA_exe->setText("VA: " +string1);
    ui->label_VB_exe->setText("VB: " +string2);
    ui->label_muxV->setText("muxV: " +string3);
    ui->label_Rps->setText("RepS: " +string4);
    ui->label_resV->setText("AluResV: " +string5);
    ui->label_dout64->setText("Dout64: "+string6);
    //QString s_ra = ;
    //QString s_rb = QString::number(rb);
    //QString s_dirc = QString::number(dir_C);
    //QString s_DinC1 = QString::number(DinC1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setProcessor(Processor* processor)
{
    this->processor =processor;
}

void MainWindow::on_boton_paso_clicked()
{
    fetch(processor);
    decode(processor);
    execution(processor);
    write_back(processor);

    ui->label_pasos->setText("Ciclos :" + QString::number(getSteps()));
    setSteps(getSteps()+1);
    refreshFetch();
    refreshDeco();
    refreshExe();
}

void MainWindow::on_ejecutar_all_clicked()
{
    pthread_t p;
    pthread_create(&p,NULL,executeInstructions,(void*)processor);
}

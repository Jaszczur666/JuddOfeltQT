#include "solverwindow.h"
#include "ui_solverwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QTableWidget>
#include "QTParser.h"
#include "QTSolver.h"

Experiment experimental;
Experiment emission;
SolverWindow::SolverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolverWindow)
{
    ui->setupUi(this);
}

SolverWindow::~SolverWindow()
{
    delete ui;
}

void SolverWindow::on_actionLoad_data_from_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
    if (fileName!="") {
        int size;
        ui->logpte->appendPlainText(fileName);
        experimental.LoadAbsoDataFromFile(fileName);
        size=experimental.u2.size();
        ui->tableWidget->setRowCount(size);
        for(int a=0;a<size;a++)
        for(int b=0;b<5;b++){
        if (ui->tableWidget->item(a,b) == 0)
        {
        QTableWidgetItem *itab = new QTableWidgetItem;
        itab->setText(" ");
        ui->tableWidget->setItem(a,b, itab);
        }}
        for (unsigned int i=0;i<experimental.u2.size();i++){
            ui->tableWidget->item(i, 0)->setText(QString::number(experimental.fexp[i],'g',3));
            ui->tableWidget->item(i, 1)->setText(QString::number(1e5*experimental.lambda[i],'g',3));
            ui->tableWidget->item(i, 2)->setText(QString::number(experimental.u2[i],'g',3));
            ui->tableWidget->item(i, 3)->setText(QString::number(experimental.u4[i],'g',3));
            ui->tableWidget->item(i, 4)->setText(QString::number(experimental.u6[i],'g',3));
        }
    }

}

void SolverWindow::on_Solvebutt_clicked()
{
    QString to2,to4,to6,MSG;
    FitLM(experimental,MSG);//.u2,experimental.u4,experimental.u6,experimental.lambda,experimental.n,experimental.j,experimental.o2,experimental.o4,experimental.o6,experimental.fexp);
    to2=QString::number(experimental.o2,'g',3);
    to4=QString::number(experimental.o4,'g',3);
    to6=QString::number(experimental.o6,'g',3);
    ui->o2->setText(to2);
    ui->o4->setText(to4);
    ui->o6->setText(to6);
    ui->do2->setText(QString::number(experimental.do2,'g',3));
    ui->do4->setText(QString::number(experimental.do4,'g',3));
    ui->do6->setText(QString::number(experimental.do6,'g',3));
    ui->doo2->setText(QString::number(100*experimental.do2/experimental.o2,'g',3)+"%");
    ui->doo4->setText(QString::number(100*experimental.do4/experimental.o4,'g',3)+"%");
    ui->doo6->setText(QString::number(100*experimental.do6/experimental.o6,'g',3)+"%");
    ui->dffl->setText(QString::number(100*(experimental.do2/experimental.o2+experimental.do4/experimental.o4+experimental.do6/experimental.o6),'g',3)+"%");
    ui->rmsl->setText(QString::number(experimental.RMS,'g',3));
    ui->rmsfl->setText(QString::number(100*experimental.RMSNormalized,'g',3)+"%");
    ui->logpte->setPlainText(MSG);
}

void SolverWindow::on_actionLoad_emission_parameters_from_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
    QString MSG;
    vector <double> a;
    if (fileName!="") {
        emission.LoadEmDataFromFile(fileName);
        emission.o2=experimental.o2;
        emission.o4=experimental.o4;
        emission.o6=experimental.o6;
        CalculateRates(emission,a,MSG);
        ui->logpte->appendPlainText(MSG);
        ui->logpte->appendPlainText(fileName);
    };
}

void SolverWindow::on_actionQuit_triggered()
{
    exit(0);
}

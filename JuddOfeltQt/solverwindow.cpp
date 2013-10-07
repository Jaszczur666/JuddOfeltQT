#include "solverwindow.h"
#include "ui_solverwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QTableWidget>
#include "QTParser.h"
#include "QTSolver.h"

Experiment experimental;

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
        LoadAbsoDataFromFile(fileName,experimental);
        size=experimental.u2.size();
        ui->tableWidget->setRowCount(size);
        for(int a=0;a<size;a++)
        for(int b=0;b<5;b++){
        if (ui->tableWidget->item(a,b) == 0)
        {
        QTableWidgetItem *itab = new QTableWidgetItem;
        itab->setText("");
        ui->tableWidget->setItem(a,b, itab);
        }}
        for (unsigned int i=0;i<experimental.u2.size();i++){
        ui->tableWidget->item(i, 1)->setText("X");

        }
    }

}

void SolverWindow::on_Solvebutt_clicked()
{
    QString to2,to4,to6;
    FitLM(experimental.u2,experimental.u4,experimental.u6,experimental.lambda,experimental.n,experimental.j,experimental.o2,experimental.o4,experimental.o6,experimental.fexp);
    to2=QString::number(experimental.o2,'g',3);
    to4=QString::number(experimental.o4,'g',3);
    to6=QString::number(experimental.o6,'g',3);
    ui->o2->setText(to2);
     ui->o4->setText(to4);
      ui->o6->setText(to6);
}

#ifndef SOLVERWINDOW_H
#define SOLVERWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class SolverWindow;
}

class SolverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SolverWindow(QWidget *parent = 0);
    ~SolverWindow();

private slots:
    void on_actionLoad_data_from_file_triggered();

    void on_Solvebutt_clicked();

    void on_actionLoad_emission_parameters_from_file_triggered();

    void on_actionQuit_triggered();

private:
    Ui::SolverWindow *ui;
};

#endif // SOLVERWINDOW_H

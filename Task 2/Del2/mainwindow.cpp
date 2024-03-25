#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_IncBtn_clicked()
{
    int incrementValue = ui->AmntSpinbox->value();
    // Increment the values of BspinBox, GspinBox, and RspinBox
    ui->BspinBox->setValue(ui->BspinBox->value() + incrementValue);
    ui->GspinBox->setValue(ui->GspinBox->value() + incrementValue);
    ui->RspinBox->setValue(ui->RspinBox->value() + incrementValue);

    Check_SpinBox_ValueChanged();




}


void MainWindow::on_DecBtn_clicked()
{
    int decrementValue = ui->AmntSpinbox->value();

    // Decrement the values of BspinBox, GspinBox, and RspinBox
    ui->BspinBox->setValue(ui->BspinBox->value() - decrementValue);
    ui->GspinBox->setValue(ui->GspinBox->value() - decrementValue);
    ui->RspinBox->setValue(ui->RspinBox->value() - decrementValue);

    Check_SpinBox_ValueChanged();

}


void MainWindow::on_CloseBtn_clicked()
{
    qApp->exit();
}


void MainWindow::Check_SpinBox_ValueChanged()
{
    int bValue = ui->BspinBox->value();
    int gValue = ui->GspinBox->value();
    int rValue = ui->RspinBox->value();

    if (bValue == 255 || gValue == 255 || rValue == 255) {
        QMessageBox::information(nullptr, "Max värde nått", "Du har nått det maximala värdet.");
    }

    if (bValue == 0 || gValue == 0 || rValue == 0) {
        QMessageBox::information(nullptr, "Min värde nått", "Du har nått det minimala värdet.");
    }
}






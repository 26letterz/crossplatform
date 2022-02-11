#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "feedback.h"
#include "controller.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::process_response(const Feedback &response, std::string mode)
{
    if (response.success == 0)
    {
       ui->label_5->setText("Error!");
       ui->label_6->clear();
    }
    else
    {
        ui->label_5->setText("Action completed!");
        if ((response.return_value == 1) && (mode == "Read"))
        {
            ui->label_6->setText(QString::fromStdString(response.content));
        }
        else if (response.return_value == 1)
        {
            ui->label_6->setText("Success!");
        }
        else if (response.return_value == 0)
        {
            ui->label_6->setText("Entry not found!");
        }
    }
}

void MainWindow::on_actionWrite_triggered()
{
    ui->label->setText("Write");
    ui->lineEdit_2->show();
    ui->label_2->setText("Key-value pair");
    ui->label_5->clear();
    ui->label_6->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_actionRead_triggered()
{
    ui->label->setText("Read");
    ui->lineEdit_2->hide();
    ui->label_2->setText("Key:");
    ui->label_5->clear();
    ui->label_6->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_actionUpdate_triggered()
{
    ui->label->setText("Update");
    ui->lineEdit_2->show();
    ui->label_2->setText("Key-value pair");
    ui->label_5->clear();
    ui->label_6->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_actionDelete_triggered()
{
    ui->label->setText("Delete");
    ui->lineEdit_2->hide();
    ui->label_2->setText("Key:");
    ui->label_5->clear();
    ui->label_6->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_clicked()
{
    Feedback response;
    QString mode = ui->label->text();
    if (mode == "Write") {
        response = controller_write(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString());
    }
    else if (mode == "Read") {
        response = controller_read(ui->lineEdit->text().toStdString());
    }
    else if (mode == "Update"){
        response = controller_update(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString());
    }
    else if (mode == "Delete") {
        response = controller_delete(ui->lineEdit->text().toStdString());
    }
    process_response(response, mode.toStdString());
}

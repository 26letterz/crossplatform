#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "feedback.h"
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionWrite_triggered();

    void on_actionRead_triggered();

    void on_actionUpdate_triggered();

    void on_actionDelete_triggered();

    void on_pushButton_clicked();
    void process_response(const Feedback &response, std::string mode);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtabwidget.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow), calculator() {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    //calcola

    ui->calcola->setText("33");
}

void MainWindow::on_tabWidget_tabBarClicked(int index) {

}

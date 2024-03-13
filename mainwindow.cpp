#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtabwidget.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow), calculator() {
    ui->setupUi(this);
    CardGroup *group = new CardGroup(ui->spinBox_9->value(), ui->spinBox_24->value());
    calculator.addGroup(*group);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    //calcola

    ui->calcola->setText(QString("Probability: ") + QString::number(calculator.Probability(), 'f', 2) + QString("%"));
}

//primo "+"
void MainWindow::on_pushButton_2_clicked() {
    if (!calculator.isSecond()) {
        CardGroup *group = new CardGroup(ui->spinBox_15->value(), ui->spinBox_25->value());
        calculator.addGroup(*group);
        calculator.setSecond(true);
    }
}

//secondo "+"
void MainWindow::on_pushButton_3_clicked() {
    if (!calculator.isThird()) {
        CardGroup *group = new CardGroup(ui->spinBox_14->value(), ui->spinBox_26->value());
        calculator.addGroup(*group);
        calculator.setThird(true);
    }
}

//primo "-"
void MainWindow::on_pushButton_5_clicked() {
    if (calculator.isThird()) {
        calculator.setThird(false);
        calculator.removeGroup(2);
    }
    calculator.setSecond(false);
    calculator.removeGroup(1);
}

//secondo "-"
void MainWindow::on_pushButton_6_clicked() {
    calculator.setThird(false);
    calculator.removeGroup(2);
}

//spinbox Decksize
void MainWindow::on_spinBox_valueChanged(int arg1) {
    calculator.setDecksize(arg1);
}

//spinbox Hand size
void MainWindow::on_spinBox_2_valueChanged(int arg1) {
    calculator.setStartinghand(arg1);
}

//spinbox 1st group number of cards
void MainWindow::on_spinBox_9_valueChanged(int arg1) {
    calculator.changeGroupN(0, arg1);

}

//spinbox 1st group number of successes
void MainWindow::on_spinBox_24_valueChanged(int arg1) {
    calculator.changeGroupS(0, arg1);
}

//spinbox 2nd group number of cards
void MainWindow::on_spinBox_15_valueChanged(int arg1) {
    calculator.changeGroupN(1, arg1);
}

//spinbox 2nd group number of successes
void MainWindow::on_spinBox_25_valueChanged(int arg1) {
    calculator.changeGroupS(1, arg1);
}

//spinbox 3rd group number of cards
void MainWindow::on_spinBox_14_valueChanged(int arg1) {
    calculator.changeGroupN(2, arg1);
}

//spinbox 3rd group number of successes
void MainWindow::on_spinBox_26_valueChanged(int arg1) {
    calculator.changeGroupS(2, arg1);
}

Calculator MainWindow::getCalc() {
    return calculator;
}

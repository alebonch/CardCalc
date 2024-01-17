#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include "math.h"
#include "iostream"
#include "Calculator.h"
#include "CardGroup.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

/*
    int decksize, startinghand, numberofgroups=0;
    std::cout << "Number of cards in deck: " << std::endl;
    std::cin>>decksize;
    std::cout << "Number of cards in starting hand: " << std::endl;
    std::cin>>startinghand;
    Calculator calculator(decksize, startinghand);
    int cardingroup;
    std::cout << "Number of cards of that group: " << std::endl;
    std::cin >> cardingroup;
    numberofgroups++;
    CardGroup group(cardingroup);
    calculator.addGroup(group);
    char input;
    int id;
    while (5 > 4) {
        std::cout << "Please select the action you want to execute:" << std::endl << "A: add group" << std::endl << "C: Calculate"
                  << std::endl << "R: remove a group" << std::endl << "T: Terminate" << std::endl;
        std::cin >> input;
        if (input == 'A') {
            std::cout << "Number of cards of that group: " << std::endl;
            std::cin >> cardingroup;
            numberofgroups++;
            CardGroup group(cardingroup);
            calculator.addGroup(group);
        } else if (input == 'C') {
            std::cout << "Total probability: " << calculator.calculategroups() << std::endl;
        } else if (input == 'R') {
            std::cout << "Insert id of group you wanna remove: " << std::endl;
            std::cin >> id;
            calculator.removeGroup(id);
        } else if (input == 'T') {
            return 0;
        } else
            std::cout << "Invalid input!" << std::endl;
    }
*/
}


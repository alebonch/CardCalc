#include <QApplication>
#include <QPushButton>
#include "math.h"
#include "iostream"
#include "Calculator.h"
#include "CardGroup.h"

int main(int argc, char *argv[]) {/*
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
    */
    int decksize, startinghand, numberofgroups=0;
    std::cout << "Number of cards in deck: " << std::endl;
    std::cin>>decksize;
    std::cout << "Number of cards in starting hand: " << std::endl;
    std::cin>>startinghand;
    Calculator calculator(decksize, startinghand);
    int cardingroup, minimuvalue;
    std::cout << "Number of cards of that group: " << std::endl;
    std::cin >> cardingroup;
    std::cout << "Minimum value you wanna draw of this group: " << std::endl;
    std::cin >> minimuvalue;
    numberofgroups++;
    CardGroup group(cardingroup, minimuvalue);
    calculator.addGroup(group);
    char input;
    int id;
    while (5 > 4) {
        std::cout << "Inserire azione da eseguire:" << std::endl << "A: aggiungi gruppo" << std::endl << "C: Calculate"
                  << std::endl << "R: rimuovi gruppo" << std::endl << "E: Termina" << std::endl;
        std::cin >> input;
        if (input == 'A') {
            std::cout << "Number of cards of that group: " << std::endl;
            std::cin >> cardingroup;
            std::cout << "Minimum value you wanna draw of this group: " << std::endl;
            std::cin >> minimuvalue;
            numberofgroups++;
            CardGroup group(cardingroup, minimuvalue);
            calculator.addGroup(group);
        } else if (input == 'C') {
            std::cout << "Probabilità totale: " << calculator.calculategroups() << std::endl;
        } else if (input == 'R') {
            std::cout << "Inserisci il numero identificativo del gruppo da rimuovere: " << std::endl;
            std::cin >> id;
        } else if (input == 'E') {
            return 0;
        } else
            std::cout << "Input non valido!" << std::endl;
    }
}


//TOD: check che funzioni la roba fatta, sistemare funzioni con puntatori o riferimenti in base alle necessità
//
// Created by alebonch on 26/09/23.
//

#ifndef CARDCALC_CALCULATOR_H
#define CARDCALC_CALCULATOR_H
#include "Card.h"


class calculator {
public:
    void addGroup(Card group);
    void changeGroupMax(int id, int value);
    void changeGroupMin(int id, int value);
    void changeGroupN(int id, int value);
    float calculate();
    calculator(int decksize, int startinghand, int numberofgroups);
    float binomialcoefficient(int n, int start);

private:
    int decksize, startinghand, numberofgroups;
    Card *groups;
};


#endif //CARDCALC_CALCULATOR_H

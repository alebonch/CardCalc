//
// Created by alebonch on 26/09/23.
//

#ifndef CARDCALC_CALCULATOR_H
#define CARDCALC_CALCULATOR_H

#include <list>
#include "CardGroup.h"


class Calculator {
public:
    Calculator(int decksize, int startinghand);

    void addGroup(const CardGroup &add);

    void removeGroup(int id);
    void changeGroupMin(int id, int value);
    void changeGroupN(int id, int value);

    float calculategroups();

    float calculate(CardGroup group);

    float binomialcoefficient(int n, int start);

    void setDecksize(const int &decksize);

    void setStartinghand(const int &startinghand);

private:
    int decksize, startinghand;
    int totalmin;
    std::list<CardGroup> groups;
};


#endif //CARDCALC_CALCULATOR_H

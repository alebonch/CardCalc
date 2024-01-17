//
// Created by alebonch on 26/09/23.
//

#ifndef CARDCALC_CALCULATOR_H
#define CARDCALC_CALCULATOR_H

#include <list>
#include <vector>
#include "CardGroup.h"
#include "iostream"
#include <cmath>


class Calculator {
public:
    Calculator(int decksize = 1, int startinghand = 1);

    void addGroup(const CardGroup &add);
    void removeGroup(int id);
    void changeGroupN(int id, int value);

    double binomC(int n, int k);

    int Probability();


    void setDecksize(const int &decksize);

    void setStartinghand(const int &startinghand);

private:
    int decksize, startinghand;
    std::vector<CardGroup> groups;
};


#endif //CARDCALC_CALCULATOR_H

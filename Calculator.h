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

    void changeGroupS(int id, int value);

    float binomC(int n, int k);

    int Probability();

    bool isSecond() const;

    bool isThird() const;

    void setSecond(bool second);

    void setThird(bool third);

    void setDecksize(const int &decksize);

    void setStartinghand(const int &startinghand);

private:
    int decksize, startinghand;
    std::vector<CardGroup> groups;

    float calculate(CardGroup group);

    bool second;
    bool third;
};


#endif //CARDCALC_CALCULATOR_H

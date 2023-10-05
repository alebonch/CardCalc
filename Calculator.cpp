//
// Created by alebonch on 26/09/23.
//

#include "Calculator.h"

/*
CardGroup* Calculator::find(const int &id) {
    int i=0;
    for(auto it=begin(groups); it!=end(groups);++it){
        if(id==i) {
            CardGroup* tmp=&it;
            return it;
        }
        else
            i++;
    }
}
*/
Calculator::Calculator(int decksize, int startinghand) : decksize(decksize), startinghand(startinghand) {
}

void Calculator::addGroup(const CardGroup &add) {
    groups.push_back(add);
}

void Calculator::removeGroup(int id) {
    auto it = groups.begin();
    int i = 0;
    while (it != groups.end()) {
        if (id == i) {
            it = groups.erase(it);
        } else {
            ++it;
        }
        ++i;
    }
}

void Calculator::changeGroupMin(int id, int value) {
    int i = 0;
    for (auto it = begin(groups); it != end(groups); ++it) {
        if (id == i) {
            it->setMin(value);
            break;
        } else
            i++;
    }
}

void Calculator::changeGroupN(int id, int value) {
    int i = 0;
    for (auto it = begin(groups); it != end(groups); ++it) {
        if (id == i) {
            it->setNumber(value);
            break;
        } else
            i++;
    }

}

float Calculator::calculategroups() {
    int i = 0;
    float final = 1;
    for (auto it = begin(groups); it != end(groups); ++it) {
        final *= calculate(*it);
    }
    return final;
}

float Calculator::calculate(CardGroup group) {
    if (group.getMinValue() < 0 or group.getMinValue() > startinghand or group.getMinValue() > decksize)
        return 0;
    float probability = 0;
    for (int i = group.getMinValue(); i < startinghand; ++i) {
        float waysToChooseGroup = binomialcoefficient(group.getNumberOfCards(), i);
        float waysToChooseOther = binomialcoefficient(decksize - group.getNumberOfCards(), startinghand - i);
        float totalWaysToChoose = binomialcoefficient(decksize, startinghand);
        probability += (waysToChooseGroup * waysToChooseOther) / totalWaysToChoose;

    }

    return probability;
}

float Calculator::binomialcoefficient(int n, int start) {
    if (start < 0 or start > n) {
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 0; i < start; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

void Calculator::setDecksize(const int &decksize) {
    Calculator::decksize = decksize;
}

void Calculator::setStartinghand(const int &startinghand) {
    Calculator::startinghand = startinghand;
}
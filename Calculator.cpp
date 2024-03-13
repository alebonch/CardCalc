//
// Created by alebonch on 26/09/23.
//

#include "Calculator.h"
Calculator::Calculator(int decksize, int startinghand) : decksize(decksize), startinghand(startinghand) {
    second = false;
    third = false;
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

void Calculator::changeGroupN(int id, int value) {

    groups.at(id).setNumber(value);
}

void Calculator::setDecksize(const int &decksize) {
    Calculator::decksize = decksize;
}

void Calculator::setStartinghand(const int &startinghand) {
    Calculator::startinghand = startinghand;
}

float Calculator::binomC(int n, int k) {
    if (k < 0 or k > n) {
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

float Calculator::Probability() {
    float final = 0;
    if (isThird()) {
        float partial;
        int sum = groups[0].getNumberOfCards() + groups[1].getNumberOfCards() + groups[2].getNumberOfCards();
        int max = startinghand - (groups[0].getSuccesses() + groups[1].getSuccesses() + groups[2].getSuccesses()) + 1;
        for (int j = groups[0].getSuccesses(); j <= max; j++) {
            partial = binomC(groups[0].getNumberOfCards(), j);
            for (int k = groups[1].getSuccesses(); k <= max; k++) {
                float partial1 = binomC(groups[1].getNumberOfCards(), k);
                for (int l = groups[2].getSuccesses(); l <= max; l++) {
                    final += partial * partial1 * binomC(groups[2].getNumberOfCards(), l) *
                             (binomC(decksize - sum, decksize - sum -
                                                     (startinghand - ((j) + (k) + (l))))) /
                             binomC(decksize, startinghand);
                }
            }
        }
        return final * 100;
    }
    if (isSecond()) {
        float partial;
        int sum = groups[0].getNumberOfCards() + groups[1].getNumberOfCards();
        int max = startinghand - (groups[0].getSuccesses() + groups[1].getSuccesses()) + 1;
        for (int j = groups[0].getSuccesses(); j <= max; j++) {
            partial = binomC(groups[0].getNumberOfCards(), j);
            for (int k = groups[1].getSuccesses(); k <= max; k++) {
                final += partial * binomC(groups[1].getNumberOfCards(), k) *
                         (binomC(decksize - sum, decksize - sum - (startinghand -
                                                                   ((j) + (k))))) / binomC(decksize, startinghand);
            }
        }
        return final * 100;
    }
    for (int j = groups[0].getSuccesses(); j <= startinghand; j++) {
        final += binomC(groups[0].getNumberOfCards(), j) *
                 (binomC(decksize - groups[0].getNumberOfCards(), decksize - groups[0].getNumberOfCards() -
                                                                  (startinghand - (j)))) /
                 binomC(decksize, startinghand);
    }
    return final * 100;

}
void Calculator::changeGroupS(int id, int value) {
    groups.at(id).setSuccesses(value);
}

bool Calculator::isSecond() const {
    return second;
}

bool Calculator::isThird() const {
    return third;
}

void Calculator::setSecond(bool second) {
    Calculator::second = second;
}

void Calculator::setThird(bool third) {
    Calculator::third = third;
}

CardGroup Calculator::getGroup(int id) {
    return this->groups[id];
}

std::vector<CardGroup> Calculator::getGroups() {
    return this->groups;
}

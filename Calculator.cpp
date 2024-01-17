//
// Created by alebonch on 26/09/23.
//

#include "Calculator.h"
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

void Calculator::setDecksize(const int &decksize) {
    Calculator::decksize = decksize;
}

void Calculator::setStartinghand(const int &startinghand) {
    Calculator::startinghand = startinghand;
}

double Calculator::binomC(int n, int k) {
    return std::exp(std::lgamma(double(n) + 1.0) - std::lgamma(double(n - k) + 1.0));
}

int Calculator::Probability() {
    double final = 1;
    int sum = 0;
    int totalsuccesses = 0;
    for (auto it: groups) {
        final *= binomC(it.getNumberOfCards(), it.getSuccesses());
        sum += it.getNumberOfCards();
        totalsuccesses += it.getSuccesses();
    }
    final = final * binomC(decksize - sum, (startinghand - totalsuccesses)) / binomC(decksize, startinghand);
    return int(final * 100);
}

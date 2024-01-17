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
    /*
    for (auto it = begin(groups); it != end(groups); ++it) {
        if (id == i) {
            it->setNumber(value);
            break;
        } else
            i++;
    }
*/
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

int Calculator::Probability() {
    float final = 1;
    for (auto it = begin(groups); it != end(groups); ++it) {
        final *= calculate(*it);
    }
    return final * 100;
}

float Calculator::calculate(CardGroup group) {
    if (group.getSuccesses() < 0 or group.getSuccesses() > startinghand or group.getSuccesses() > decksize)
        return 0;
    float probability = 0;
    for (int i = group.getSuccesses(); i < startinghand; ++i) {
        float waysToChooseGroup = binomC(group.getNumberOfCards(), i);
        float waysToChooseOther = binomC(decksize - group.getNumberOfCards(), startinghand - i);
        float totalWaysToChoose = binomC(decksize, startinghand);
        probability += (waysToChooseGroup * waysToChooseOther) / totalWaysToChoose;

    }

    return probability;
}

/*
double Calculator::binomC(int n, int k) {
    return std::exp(std::lgamma(double(n) + 1.0) - std::lgamma(double(n - k) + 1.0));
}

int Calculator::Probability() {
    double final = 0;
    int sum = 0;
    int totalsuccesses = 0;
    for (auto it: groups) {
        final += binomC(it.getNumberOfCards(), it.getSuccesses());
        sum += it.getNumberOfCards();
        totalsuccesses += it.getSuccesses();
    }
    final = final + binomC(decksize - sum, (startinghand - totalsuccesses)) - binomC(decksize, startinghand);
    return int(final * 100);
}
 */
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

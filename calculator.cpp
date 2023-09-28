//
// Created by alebonch on 26/09/23.
//

#include "calculator.h"

void calculator::addGroup(Card add) {
    int size= this->numberofgroups+1;
    Card *ngroup;
    for (int i = 0; i < size-1; ++i) {
        ngroup[i]= this->groups[i];
    }
    ngroup[size]=add;
    this->numberofgroups++;
    this->groups=ngroup;
}

void calculator::changeGroupMax(int id, int value) {
    this->groups[id].setMax(value);
}

void calculator::changeGroupMin(int id, int value) {
    this->groups[id].setMin(value);
}

void calculator::changeGroupN(int id, int value) {
    this->groups[id].setNumber(value);

}

float calculator::calculate() {
    float result;
    float final=1;
    for (int i = 0; i < numberofgroups; ++i) {
        result= binomialcoefficient(this->decksize-groups[i].getNumberOfCards(), this->startinghand);
        result=result/ binomialcoefficient(this->decksize, this->startinghand);
        this->groups[i].setProbability(result);
        for(int j=0; j<startinghand&&this->groups[i].getMinValue()>1;j++) {
            result+= (this->groups[i].getNumberOfCards()* binomialcoefficient(this->decksize-groups[i].getNumberOfCards(),
                                                                              this->startinghand-j))/
                     binomialcoefficient(this->decksize, this->startinghand);
            this->groups[i].setProbability(result);
        }
        final*=result;
    }
    final-=1;
    return final;
}

calculator::calculator(int decksize, int startinghand, int numberofgroups) : decksize(decksize),
                                                                             startinghand(startinghand),
                                                                             numberofgroups(numberofgroups) {}

float calculator::binomialcoefficient(int n, int start) {
    if (start < 0 || start > n) {
        return 0; // Invalid input
    }
    unsigned long long result = 1;
    for (int i = 0; i < start; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

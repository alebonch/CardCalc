//
// Created by alebonch on 25/09/23.
//

#include "CardGroup.h"

CardGroup::CardGroup(int numberOfCards, int successes) : NumberOfCards(numberOfCards), Successes(successes) {}

void CardGroup::setNumber(const int &value) {
    this->NumberOfCards=value;

}

int CardGroup::getNumberOfCards() const {
    return NumberOfCards;
}

int CardGroup::getSuccesses() const {
    return this->Successes;
}

void CardGroup::setSuccesses(int successes) {
    Successes = successes;
}


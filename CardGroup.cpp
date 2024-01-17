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
void CardGroup::setStringName(const std::string &groupname) {
    this->GroupName = groupname;
}

std::string CardGroup::getStringName() {
    return this->GroupName;
}

int CardGroup::getSuccesses() const {
    return this->Successes;
}


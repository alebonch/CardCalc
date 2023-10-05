//
// Created by alebonch on 25/09/23.
//

#include "CardGroup.h"

CardGroup::CardGroup(int numberOfCards, int minValue) : NumberOfCards(numberOfCards), minValue(minValue) {}

void CardGroup::setMin(const int &value) {
    this->minValue=value;
}

void CardGroup::setMax(const int &value) {
    this->maxValue=value;
}

void CardGroup::setNumber(const int &value) {
    this->NumberOfCards=value;

}

int CardGroup::getNumberOfCards() const {
    return NumberOfCards;
}

int CardGroup::getMinValue() const {
    return minValue;
}

int CardGroup::getMaxValue() const {
    return maxValue;
}

void CardGroup::setStringName(const std::string &groupname) {
    this->GroupName = groupname;
}

std::string CardGroup::getStringName() {
    return this->GroupName;
}


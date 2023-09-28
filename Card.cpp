//
// Created by alebonch on 25/09/23.
//

#include "Card.h"

Card::Card(int numberOfCards, int minValue, int maxValue, int id) : NumberOfCards(numberOfCards), minValue(minValue),
                                                                      maxValue(maxValue), id(id) {}

void Card::setMin(int value) {
    this->minValue=value;
}

void Card::setMax(int value) {
    this->maxValue=value;
}

void Card::setNumber(int value) {
    this->NumberOfCards=value;

}

int Card::getId() {
    return this->id;
}

void Card::setProbability(float value) {
    this->probability=value;
}

float Card::getProbability() {
    return this->probability;
}

int Card::getNumberOfCards() const {
    return NumberOfCards;
}

int Card::getMinValue() const {
    return minValue;
}

int Card::getMaxValue() const {
    return maxValue;
}

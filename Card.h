//
// Created by alebonch on 25/09/23.
//

#ifndef CARDCALC_GROUP_H
#define CARDCALC_GROUP_H


class Card {
public:
    Card(int numberOfCards, int minValue, int maxValue, int id);
    void setMin(int value);
    void setMax(int value);
    void setNumber(int value);
    int getId();
    void setProbability(float value);
    float getProbability();

    int getNumberOfCards() const;

    int getMinValue() const;

    int getMaxValue() const;

private:
    int NumberOfCards;
    int minValue;
    int maxValue;
    float probability=0;
    int id;
};


#endif //CARDCALC_GROUP_H

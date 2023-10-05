//
// Created by alebonch on 25/09/23.
//

#ifndef CARDCALC_CARDGROUP_H
#define CARDCALC_CARDGROUP_H

#include <string>


class CardGroup {
public:
    CardGroup(int numberOfCards, int minValue);

    void setMin(const int &value);

    void setMax(const int &value);

    void setNumber(const int &value);

    void setStringName(const std::string &groupname);

    std::string getStringName();

    int getNumberOfCards() const;

    int getMinValue() const;

    int getMaxValue() const;

private:
    int NumberOfCards;
    int minValue;
    int maxValue;
    std::string GroupName;
};


#endif //CARDCALC_CARDGROUP_H

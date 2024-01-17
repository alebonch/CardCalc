//
// Created by alebonch on 25/09/23.
//

#ifndef CARDCALC_CARDGROUP_H
#define CARDCALC_CARDGROUP_H

#include <string>


class CardGroup {
public:
    CardGroup(int numberOfCards, int successes);

    void setNumber(const int &value);

    void setStringName(const std::string &groupname);

    std::string getStringName();

    int getNumberOfCards() const;

    int getSuccesses() const;

    void setSuccesses(int successes);

private:
    int NumberOfCards;
    std::string GroupName;
    int Successes;
};


#endif //CARDCALC_CARDGROUP_H

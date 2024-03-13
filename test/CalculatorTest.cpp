//
// Created by alebonch on 11/03/24.
//
#include "QtTest/QTest"
#include "../Calculator.h"
#include "../CardGroup.h"

class CalculatorTest : public QObject {
Q_OBJECT

private slots:

    void testAddingGroup() {
        Calculator calc(40, 5);
        CardGroup cardGroup(10, 1);
        calc.addGroup(cardGroup);
        QVERIFY(calc.getGroup(0).getNumberOfCards() == 10);
        QVERIFY(calc.getGroup(0).getSuccesses() == 1);
        CardGroup cardGroup1(5, 1);
        calc.addGroup(cardGroup1);
        QVERIFY(calc.getGroup(1).getNumberOfCards() == 5);
        QVERIFY(calc.getGroup(1).getSuccesses() == 1);
        CardGroup cardGroup2(8, 1);
        calc.addGroup(cardGroup2);
        QVERIFY(calc.getGroup(2).getNumberOfCards() == 8);
        QVERIFY(calc.getGroup(2).getSuccesses() == 1);
        QVERIFY(calc.getGroups().size() == 3);
    }

    void testRemovingGroup() {
        Calculator calc(40, 5);
        CardGroup cardGroup(10, 1);
        calc.addGroup(cardGroup);
        CardGroup cardGroup1(5, 1);
        calc.addGroup(cardGroup1);
        CardGroup cardGroup2(8, 1);
        calc.addGroup(cardGroup2);
        calc.removeGroup(0);
        QVERIFY(calc.getGroup(0).getNumberOfCards() == 5);
        QVERIFY(calc.getGroup(0).getSuccesses() == 1);
        QVERIFY(calc.getGroups().size() == 2);

    }

    void testBinomC() {
        Calculator calc(40, 5);
        QVERIFY(calc.binomC(5, 2) == 10);
        QVERIFY(calc.binomC(8, 4) == 70);
        QVERIFY(calc.binomC(10, 2) == 45);
    }

    void testProbability() {
        Calculator calc(40, 5);
        CardGroup cardGroup(10, 1);
        calc.addGroup(cardGroup);
        QVERIFY(int(calc.Probability())==78);
        CardGroup cardGroup1(8, 1);
        calc.addGroup(cardGroup1);
        calc.setSecond(true);
        QVERIFY(int(calc.Probability())==51);
        CardGroup cardGroup2(15, 1);
        calc.addGroup(cardGroup2);
        calc.setThird(true);
        QVERIFY(int(calc.Probability())==45);
    }
};

QTEST_MAIN(CalculatorTest);

#include "CalculatorTest.moc"




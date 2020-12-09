//
// Created by Katya on 07.12.2020.
//

#ifndef TEST_TEMPLATE_ROBOT_H
#define TEST_TEMPLATE_ROBOT_H
#include "Map.h"
#include <string>


class Robot {
public:
    Map robotsMap;
    virtual void step(string direction) = 0;
};

class Collector : public Robot{
private:
    int collectedApplesNumber;
    int xCoordinate;
    int yCoordinate;
    void stepHelperX(int newCoordinate);
    void stepHelperY(int newCoordinate);
public:
    Collector(int i, int j);
    void step(string direction) override;
    void scan(Map& map);
};


#endif //TEST_TEMPLATE_ROBOT_H

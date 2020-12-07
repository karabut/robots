//
// Created by Katya on 07.12.2020.
//

#ifndef TEST_TEMPLATE_ROBOT_H
#define TEST_TEMPLATE_ROBOT_H
#include "Map.h"


class Robot {
public:
    Map robotsMap;
    virtual void step() = 0;
};

class Collector : public Robot{
private:
    int collectedApplesNumber;
    int xCoordinate;
    int yCoordinate;
public:
    //randomly finds the position for robot
    //Collector();
    Collector(int i, int j);
    void step() override;
};


#endif //TEST_TEMPLATE_ROBOT_H

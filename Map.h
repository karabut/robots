//
// Created by Katya on 07.12.2020.
//

#ifndef TEST_TEMPLATE_MAP_H
#define TEST_TEMPLATE_MAP_H
#include <string>
using namespace std;

enum Cell{
    robot = 0, apple = 2, empty = 3, rock = 4
};

class Map {
private:
     int totalX;
     int totalY;
     char** board;
     int applesTotalNumber;
public:
    void setRobot(int i, int j);
    void draw();
    void makeUnknown();
    Map();

    //constructor that initialise everything unknown and put robot to i j;
    Map(int i, int j);
    //everything unknown and without robot
};


#endif //TEST_TEMPLATE_MAP_H

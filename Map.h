//
// Created by Katya on 07.12.2020.
//

#ifndef TEST_TEMPLATE_MAP_H
#define TEST_TEMPLATE_MAP_H

enum Cell{
    robot = 0, apple = 2, empty = 3, rock = 4
};

class Map {
private:
     int totalX;
     int totalY;
     char** board;
public:
    void setRobot(int i, int j);
    void draw();
    Map();
};


#endif //TEST_TEMPLATE_MAP_H

//
// Created by Katya on 08.12.2020.
//

#ifndef TEST_TEMPLATE_COMMAND_H
#define TEST_TEMPLATE_COMMAND_H
#include <string>
#include "Robot.h"
using namespace std;

class Command {
public:
    virtual void applyToRobot(Robot& robot) = 0;
    //void virtual applyToMode() = 0;
};

class Move: public Command {
private:
    string direction;
public:
    Move(string _direction);
    void applyToRobot(Robot& robot) override;
};


#endif //TEST_TEMPLATE_COMMAND_H

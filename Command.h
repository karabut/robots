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
    virtual void apply(Robot& robot) = 0;
};

class Move: public Command {
private:
    string direction;
public:
    Move(string _direction);
    void apply(Robot& robot) override;
};


#endif //TEST_TEMPLATE_COMMAND_H

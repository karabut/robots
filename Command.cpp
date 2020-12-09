//
// Created by Katya on 08.12.2020.
//

#include "Command.h"

Move::Move(string _direction) {
    direction = _direction;
}

void Move::applyToRobot(Robot& robot) {
robot.step(direction);
//TODO probably works
}


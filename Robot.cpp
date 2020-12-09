//
// Created by Katya on 07.12.2020.
//

#include "Robot.h"
#include <iostream>

Collector::Collector(int x, int y) {
collectedApplesNumber = 0;
xCoordinate = x;
yCoordinate = y;
robotsMap.makeUnknown();
robotsMap.setRobot(x, y);
}


void Collector::stepHelperX(int newCoordinate) {
    if(robotsMap.whatIsInCell(newCoordinate, yCoordinate) == "rock"){
        //do nothing
    }

    if(robotsMap.whatIsInCell(newCoordinate, yCoordinate) == "apple"){
        robotsMap.setEmpty(xCoordinate, yCoordinate);
        robotsMap.setRobot(newCoordinate, yCoordinate);
        xCoordinate = newCoordinate;
        collectedApplesNumber ++;
    }

    if(robotsMap.whatIsInCell(newCoordinate, yCoordinate) == "empty"){
        robotsMap.setEmpty(xCoordinate, yCoordinate);
        robotsMap.setRobot(newCoordinate, yCoordinate);
        xCoordinate = newCoordinate;
    }

    if(robotsMap.whatIsInCell(newCoordinate, yCoordinate) == "bomb") {
        cout << "Robot stepped on bomb == Game over" << endl;
        exit(0);
    }
}

void Collector::stepHelperY(int newCoordinate) {

    if(robotsMap.whatIsInCell(xCoordinate, newCoordinate) == "rock"){
        //do nothing
    }

    if(robotsMap.whatIsInCell(xCoordinate, newCoordinate) == "apple"){
        //todo also check for apples number
        robotsMap.setEmpty(xCoordinate, yCoordinate);
        robotsMap.setRobot(xCoordinate, newCoordinate);
        yCoordinate = newCoordinate;
        collectedApplesNumber ++;
    }

    if(robotsMap.whatIsInCell(xCoordinate, newCoordinate) == "empty"){

        robotsMap.setEmpty(xCoordinate, yCoordinate);
        robotsMap.setRobot(xCoordinate, newCoordinate);
        yCoordinate = newCoordinate;
        robotsMap.draw();
    }

    if(robotsMap.whatIsInCell(xCoordinate, newCoordinate) == "bomb") {
        cout << "Robot stepped on bomb == Game over" << endl;
        exit(0);
    }
}

void Collector::step(string direction) {

    if(direction == "U" && (xCoordinate - 1 >= 0)){

        stepHelperX(xCoordinate - 1);

    }

    if(direction == "D" && (xCoordinate + 1 < robotsMap.getXCoordinate()) ){

        stepHelperX(xCoordinate + 1);
    }

    if(direction == "L" && (yCoordinate - 1 >= 0)){

        stepHelperY(yCoordinate - 1);

    }

    if(direction == "R" && (yCoordinate + 1 < robotsMap.getYCoordinate())){

        stepHelperY(yCoordinate + 1);
    }

}

void Collector::scan(Map& map) {

    if(xCoordinate - 1 >= 0){
        robotsMap.Eq(xCoordinate - 1, yCoordinate, map);
    }

    if(xCoordinate + 1 < robotsMap.getXCoordinate()){
        robotsMap.Eq(xCoordinate + 1, yCoordinate, map);
    }

    if(yCoordinate - 1 >= 0){
        robotsMap.Eq(xCoordinate, yCoordinate - 1, map);
    }

    if(yCoordinate + 1 < robotsMap.getYCoordinate()){
        robotsMap.Eq(xCoordinate, yCoordinate + 1, map);
    }

}


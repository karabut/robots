//
// Created by Katya on 07.12.2020.
//

#include "Robot.h"

Collector::Collector(int i, int j) {
collectedApplesNumber = 0;
xCoordinate = i;
yCoordinate = j;
robotsMap.makeUnknown();
robotsMap.setRobot(i, j);
}

#include <iostream>
#include "Map.h"
#include "Robot.h"
#include "Command.h"
#include "Parser.h"
using namespace std;
int main() {
 Map k;
 k.draw();
 cout << endl;

 Collector collector (0,1);
 collector.robotsMap.draw();
 cout << endl;

 collector.robotsMap.setEmpty(1,1);
 collector.robotsMap.draw();

 Parser parser;
 Command* command = parser.readNextCommand();
 command->applyToRobot(collector);
 cout << " " << endl;
 collector.robotsMap.draw();
}

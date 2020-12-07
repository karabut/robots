//
// Created by Katya on 07.12.2020.
//

#include "Map.h"
#include <fstream>
#include <iostream>
using namespace std;

 Map::Map() {
     ifstream file;
     file.open("/Users/katya/CLionProjects/robots/Map.txt");

    if(!file.is_open()){
        cout << "can't open the file" << endl;
    } else {
        cout << "opened the file" << endl;
        file >> totalX;
        file >> totalY;
        cout << totalX << " " << totalY << endl;

        board = new char*[totalX];
        for(int i = 0; i < totalX; i ++){
            board[i] = new char[totalY];
        }

        for(int i = 0; i < totalX; i++){
            for(int j = 0; j < totalY; j ++){
                file >> board[i][j];
            }
        }
    }

    file.close();
}

void Map::draw() {
    for(int i = 0; i < totalX; i ++){
        for(int j = 0; j < totalY; j ++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Map::setRobot(int i, int j) {
    board[i][j] = 'R';
}

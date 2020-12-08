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
        file >> totalX;
        file >> totalY;
        applesTotalNumber = 0;

        board = new char*[totalX];
        for(int i = 0; i < totalX; i ++){
            board[i] = new char[totalY];
        }

        for(int i = 0; i < totalX; i++){
            for(int j = 0; j < totalY; j ++){
                file >> board[i][j];
                if(board[i][j] == 'a'){
                    applesTotalNumber++;
                }
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

void Map::setEmpty(int i, int j) {
    board[i][j] = '*';
}

Map::Map(int k, int m) {
    ifstream file;
    file.open("/Users/katya/CLionProjects/robots/Map.txt");

    if(!file.is_open()){
        cout << "can't open the file" << endl;
    } else {
        applesTotalNumber = 0;
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
                char is_apple;
                file >> is_apple;
                if(is_apple == 'a'){
                    applesTotalNumber++;
                }
                board[i][j] = '?';
            }
        }
    }

    setRobot(k , m);

    file.close();
}

void Map::makeUnknown() {
    for(int i = 0; i < totalX; i++){
        for(int j = 0; j < totalY; j ++){
            board[i][j] = '?';
        }
    }
}

string Map::whatIsInCell(int i, int j) {
     if(board[i][j] == '*'){
         return "empty";
     }

     if(board[i][j] == '?'){
         return "unknown";
     }

     if(board[i][j] == 'A'){
         return "apple";
     }

     if(board[i][j] == 'r'){
         return "rock";
     }

     if(board[i][j] == 'b'){
         return "bomb";
     }

     return "error";
}

int Map::getYCoordinate() {
    return totalY;
}

int Map::getXCoordinate() {
     return totalX;
 }


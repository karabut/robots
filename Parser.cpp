//
// Created by Katya on 08.12.2020.
//

#include "Parser.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//change to * change clear from .  to -> and pushback twice
void split(const string &txt, vector<string>* strs, char ch) //was size_t
{
    size_t pos = txt.find( ch ); //the location of ' '
    size_t initialPos = 0;
    strs->clear(); // empty strings with length of 0 characters

    //Decompose statement
    //string::npos == didn't find the position in text
    //if found the position then enter the while
    while( pos != std::string::npos ) {
        strs->push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs->push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    //return strs.size();
}

Command* Parser::readNextCommand() {
    string line;

    getline(cin, line);


    vector<string> parts; // line - entered from cin, parts - where to copy

    split(line, &parts, ' ');

    if(parts[0] == "MOVE"){
        return new Move(parts[1]);
    }

    //TODO much more commands
}
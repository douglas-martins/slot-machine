//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/symb.h"
#include "../headers/defaultIncludes.h"

string checkSymbAmount (char symb, int count) {
    string returnS;
    count > 2 ? returnS.append(3, symb) : returnS.append(2, symb);
    return returnS;
}

int findMultiplier (string type) {
    int count = type.size();
    int resultReturn = 0;
    char symb = type.at(0);
    switch (symb) {
        case '$':
            resultReturn = count > 2 ? THREE_MONEY_SYMB : TWO_MONEY_SYMB;
            break;
        case '#':
            resultReturn = count > 2 ? THREE_HASHTAG_SYMB : TWO_HASHTAG_SYMB;
            break;
        default:break;
    }
    return resultReturn;
}


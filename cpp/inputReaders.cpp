//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/inputReaders.h"
#include "../headers/screen.h"

int readIntPositiveNumber (string msg, short width, short height) {
    int number = 0;

    do {
        setMsgOnPosition("               ", width, height); // clean for bug reasons
        setMsgOnPosition(msg, width, height);
        cin >> number; // miss check if only press enter
    } while (number < 0 || number == '\r');
    return number;
}

char readCharYesNo (string msg, short width, short height) {
    char result;

    do {
        setMsgOnPosition("                                             ", width, height); // clean for bug reasons
        setMsgOnPosition(msg, width, height);
        cin >> result;
    } while (toupper(result) != 'Y' && toupper(result) != 'N');

    return result;
}

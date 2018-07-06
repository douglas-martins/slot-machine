//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/inputReaders.h"
#include "../headers/screen.h"

int readIntPositiveNumber (string msg, short width, short height) {
    int number = -1;
    string line;
    string::size_type stringSizeType;

    do {
        setMsgOnPosition("               ", width, height); // clean for bug reasons
        setMsgOnPosition(msg, width, height);
        getline(cin, line); // get the entire line, this prevents the users to input only enter
        if (line.size() > 0) number = stoi(line, &stringSizeType); // convert the string to integer, if the string is not empty
    } while (number < 0);

    return number;
}

char readCharYesNo (string msg, short width, short height) {
    char result;
    string line;
    string::size_type stringSizeType;

    do {
        setMsgOnPosition("                                             ", width, height); // clean for bug reasons
        setMsgOnPosition(msg, width, height);
        getline(cin, line);
        if (line.size() == 1) result = line.at(0);
    } while (toupper(result) != 'Y' && toupper(result) != 'N');

    return result;
}

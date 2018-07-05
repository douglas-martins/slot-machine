//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/inputReaders.h"
#include "../headers/screen.h"

int readIntPositiveNumber (string msg, short width, short height) {
    int number = 0;

    do {
        setMsgOnPosition("", width, height);
        //cout << msg << ": ";
        cin >> number;
    } while (number <= 0);
    //cout << endl;
    return number;
}

char readCharYesNo (string msg) {
    char result;

    do {
        cout << msg << ": " << endl;
        cin >> result;
    } while (toupper(result) != 'Y' && toupper(result) != 'N');

    system("cls");
    return result;
}




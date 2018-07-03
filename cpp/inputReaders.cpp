//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/inputReaders.h"

int readIntPositiveNumber (string msg) {
    int number = 0;

    do {
        cout << msg << ": ";
        cin >> number;
    } while (number <= 0);

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




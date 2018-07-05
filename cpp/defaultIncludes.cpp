//
// Created by Douglas Martins on 05/07/2018.
//

#include "../headers/defaultIncludes.h"

string setIntNumberPrecision (int number, int precision) {
    stringstream stream;
    stream << fixed << setprecision(precision) << number;
    string numText = stream.str();
    return numText;
}

string setRealNumberPrecision (float number, int precision) {
    stringstream stream;
    stream << fixed << setprecision(precision) << number;
    string numText = stream.str();
    return numText;
}


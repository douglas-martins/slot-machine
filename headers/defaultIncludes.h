//
// Created by Douglas Martins on 01/07/2018.
//

#ifndef SLOT_MACHINE_INCLUDES_H
#define SLOT_MACHINE_INCLUDES_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <string>
#include "../headers/screen.h"

using namespace std;

int const AMOUNT_SYMBOLS = 3;
int const THREE_MONEY_SYMB = 30;
int const TWO_MONEY_SYMB = 7;
int const THREE_HASHTAG_SYMB = 5;
int const TWO_HASHTAG_SYMB = 2;
string const TITLE = "SLOT - MACHINE";
string const BET = "BET";
string const COINS = "Coins of ";
string const ZERO_DOT_25_BET = "$ 0.25: ";
string const ZERO_DOT_50_BET = "$ 0.50: ";
string const ONE_BET = "$ 1.00: ";
string const RESULT = "RESULT";
string const BET_MOD = "Your bet wil be multiplied by ";
const string
        u2550 = "\u2550", // ═
        u2551 = "\u2551", // ║
        u2569 = "\u2569", //╩
        u2564 = "\u2564", // ╤
        u2566 = "\u2566", // ╦
        u256B = "\u256B", //  ╫
        u255A = "\u255A", //╚
        u2554 = "\u2554", // ╔
        u255D = "\u255D", //╝
        u2557 = "\u2557", //╗
        u2560 = "\u2560", // ╠
        u2563 = "\u2563"; //╣

string setIntNumberPrecision (int number, int precision);
string setRealNumberPrecision (float number, int precision);

#endif //SLOT_MACHINE_INCLUDES_H

//
// Created by Douglas Martins on 01/07/2018.
//
#ifndef SLOT_MACHINE_BET_H
#define SLOT_MACHINE_BET_H
#include <math.h>
#include <iomanip>
#include <sstream>
#include "../headers/defaultIncludes.h"

char checkBetterMoney(int money);
string checkBetGenerateResult(char current[]);
float calculateBetResult(float& bet, int& multiplier);
float placeBet (int size, float values[], float& money);
void generateBetResult(int size, char slotSymbols[], char current[]);
float roundValue (float value);

#endif //SLOT_MACHINE_BET_H


//
// Created by Douglas Martins on 01/07/2018.
//

#ifndef SLOT_MACHINE_GENERATERESULTS_H
#define SLOT_MACHINE_GENERATERESULTS_H
#include <cstring>
#include <cctype>
#include <iomanip>
#include <sstream>
#include "../headers/defaultIncludes.h"

string showPlayResult (string result, float gain);
void showFinalResult (char keep, float startMoney, float finalMoney, short width, short height);

#endif //SLOT_MACHINE_GENERATERESULTS_H

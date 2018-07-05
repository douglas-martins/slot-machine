//
// Created by Douglas Martins on 01/07/2018.
//

#ifndef SLOT_MACHINE_SCREEN_H
#define SLOT_MACHINE_SCREEN_H
#ifdef TARGET_OS_WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <cstdlib>
#include <stdio.h>
#endif
#include <iostream>
#include "../headers/defaultIncludes.h"
using namespace std;

void setPositionXYOnScreen (short x, short y);
void drawScreenBorders (short width, short height);
void drawDefaultMsgs (short width, short height);
void drawMachineSlots(short width, short height);
void drawSymbolOnPosition (string unicodeSymb, short x, short y);
void setMsgOnPosition (string msg, short x, short y);
void cleanScreen();

#endif //SLOT_MACHINE_SCREEN_H

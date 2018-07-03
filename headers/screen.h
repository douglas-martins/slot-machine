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
using namespace std;

void setPositionXYOnScreen (short x, short y);
void drawScreenBorders (short& width, short& height);

#endif //SLOT_MACHINE_SCREEN_H

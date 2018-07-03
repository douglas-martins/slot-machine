//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/screen.h"

void setPositionXYOnScreen (short x, short y) {
    printf("\033[%d;%dH", (x), (y));
    //cout << "\u2588" << endl; // unicode for draw on screen border
}

void drawScreenBorders (short& width, short& height) {
    short middleScreenX = width / 2;
    short middleScreenY = height / 2;

    for (int i = 0; i <= width; i++) {
        for (int j = 0; j <= height; j++) {
            setPositionXYOnScreen(i, j);
            cout << "a";
        }
    }
}
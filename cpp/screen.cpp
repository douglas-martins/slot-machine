//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/screen.h"

void setPositionXYOnScreen (short x, short y) {
    printf("\033[%d;%dH", (x+1), (y+1));
}

void drawSymbolOnPosition (string unicodeSymb, short x, short y) {
    setPositionXYOnScreen(x, y);
    cout << unicodeSymb; // has to be the cout << endl; to work at the end
}

void setMsgOnPosition (string msg, short x, short y) {
    setPositionXYOnScreen(x, y);
    cout << msg;
}

void drawScreenBorders (short& width, short& height) {
    short middleScreenX = width / 2;
    short middleScreenY = height / 2;

    // down borders
    for (int i = 0; i < height; i++) {
        drawSymbolOnPosition(u2550, height, i); // clear problem compensation
    }

    // left borders
    for (int i = 0; i < width; i++) {
        drawSymbolOnPosition(u2551, i, 0);
    }

    // right borders
    for (int i = 0; i < width; i++) {
        drawSymbolOnPosition(u2551, i, height);
    }
    drawSymbolOnPosition(u255A, width, 0); // left down
    drawSymbolOnPosition(u255D, height, height); // right down

    // upper borders
    for (int i = 0; i < height; i++) {
        drawSymbolOnPosition(u2550, 0, i); // clear problem compensation
    } // has to be the last to draw
    drawSymbolOnPosition(u2554, 0, 0); // left upper
    drawSymbolOnPosition(u2557, 0, height); // right upper

    // divisors
    // program name divisor
    for (int i = 1; i < height-1; i++) { // init 1 for not begin on borders
        drawSymbolOnPosition(u2550, 3, i);
    }

    // result divisor
    for (int i = 1; i < height-1; i++) { // init 1 for not begin on borders (-1 same)
        drawSymbolOnPosition(u2550, 20, i);
    }

    // middle divisor
    for (int i = 4; i < width-4; i++) { // init 4 for not begin on borders divisors up and down (-4 same)
        drawSymbolOnPosition(u2551, i, middleScreenY);
    }


    cout << endl; // to make work, has to endl for draw work
}

void cleanScreen () {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
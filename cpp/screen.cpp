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

void drawScreenBorders (short width, short height) {
    short middleScreenX = (width / 2);
    short middleScreenY = (height / 2);
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
    drawSymbolOnPosition(u2566, 3, middleScreenY); // the interpolate symbol up
    for (int i = 4; i < width-4; i++) { // init 4 for not begin on borders divisors up and down (-4 same)
        drawSymbolOnPosition(u2551, i, middleScreenY);
    }
    drawSymbolOnPosition(u2569, width-4, middleScreenY); // the interpolate symbol down

    cout << endl; // to make work, has to endl for draw work
}

void drawDefaultMsgs (short width, short height) {
    short middleScreenX = (width / 2);
    short middleScreenY = (height / 2);

    setMsgOnPosition(TITLE, 2, middleScreenY-6); // title of the program (-6 for tuning)
    setMsgOnPosition(BET, 5, middleScreenY/2-2); // bet local title (middle of the middle of the screen)
    setMsgOnPosition("CURRENT MONEY $ ", 8, middleScreenY/6); // current money text default position
    setMsgOnPosition("LAST BET $ ", 9, middleScreenY/6); // current last bet text default position
    setMsgOnPosition(COINS, 12, middleScreenY/6); // coins of text
    setMsgOnPosition(ZERO_DOT_25_BET, 12, middleScreenY-25); // $ 0.25 bet text place
    setMsgOnPosition(ZERO_DOT_50_BET, 13, middleScreenY-25); // $ 0.50 bet text place
    setMsgOnPosition(ONE_BET, 14, middleScreenY-25); // $ 1.00 bet text place
    setMsgOnPosition(RESULT, 5, middleScreenY+17); // result local tittle (+15 for tuning)

    cout << endl;
}

void drawMachineSlots(short width, short height) {
    short middleScreenX = (width / 2);
    short middleScreenY = (height / 2);

    for (int i = (middleScreenY+13); i < (middleScreenY+28); i++) { // upper result box
        setMsgOnPosition(u2550, 8, i);
    }

    for (int i = (middleScreenY+13); i < (middleScreenY+28); i++) { // down result box
        setMsgOnPosition(u2550, 10, i);
    }

    setMsgOnPosition(u2551, 9, middleScreenY+12); // left bar of the result box
    setMsgOnPosition(u2551, 9, middleScreenY+12); // left bar of the result box
    setMsgOnPosition(u2554, 8, middleScreenY+12); // corner left up for result box

    setMsgOnPosition(u2551, 10, middleScreenY+17); // first coll divisors for slots
    setMsgOnPosition(u2551, 9, middleScreenY+17); // first coll divisors for slots
    setMsgOnPosition(u2566, 8, middleScreenY+17); // first up corner for divisors
    setMsgOnPosition(u2569, 10, middleScreenY+17); // first up corner for divisors

    setMsgOnPosition(u2551, 10, middleScreenY+23); // second coll divisors for slots
    setMsgOnPosition(u2551, 9, middleScreenY+23); // second coll divisors for slots
    setMsgOnPosition(u2566, 8, middleScreenY+23); // second corner for divisors
    setMsgOnPosition(u2569, 10, middleScreenY+23); // second up corner for divisors

    setMsgOnPosition(u2557, 8, middleScreenY+28); // corner up right for result box
    setMsgOnPosition(u2551, 9, middleScreenY+28); // right bar of the result box
    //setMsgOnPosition(u2551, 9, middleScreenY+28); // right bar of the result box

    setMsgOnPosition(u255D, 10, middleScreenY+28); // corner down right for result box
    setMsgOnPosition(u255A, 10, middleScreenY+12); // corner down left for result box

    cout << endl;
}

void drawModGained (string bet, short width, short height) {
    short middleScreenX = (width / 2);
    short middleScreenY = (height / 2);


    setMsgOnPosition(BET_MOD+bet, 18, middleScreenY/2+25); // show bet modifier if the better win
    cout << endl;
}

void newPlayClearScreen(short width, short height) {
    short middleScreenX = (width / 2);
    short middleScreenY = (height / 2);
    // bet
    for (int i = 0; i < AMOUNT_SYMBOLS; i++) {
        setMsgOnPosition("               ", (12+i), (middleScreenY/2)-44);
    }

    laterNewPlayClearScreen(width, height);
    setMsgOnPosition("                                   ", 22, middleScreenY-44); // ask to continue the game

    cout << endl;
}

void laterNewPlayClearScreen(short width, short height) {
    short middleScreenX = (width / 2);
    short middleScreenY = (height / 2);
    int jumpSlots = 0;

    // later
    // slots
    for (int i = 0; i < AMOUNT_SYMBOLS; i++) {
        setMsgOnPosition(" ", 9, middleScreenY+(14+jumpSlots));
        jumpSlots += 6;
    }

    setMsgOnPosition("                                   ", 18, middleScreenY-44); // bet info
    setMsgOnPosition("                                   ", 19, middleScreenY-44); // confirm bet

    // multiplied text
    setMsgOnPosition("                                  ", 18, (middleScreenY/2)+25);

    // results
    setMsgOnPosition("                                        ", 21, middleScreenY-44);
    cout << endl;
}

void clearBetScreen (short width, short height) {
    short middleScreenX = (width / 2);
    short middleScreenY = (height / 2);

    for (int i = 0; i < AMOUNT_SYMBOLS; i++) {
        setMsgOnPosition("               ", (12+i), (middleScreenY/2)-44);
    }
}

void cleanScreen () {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
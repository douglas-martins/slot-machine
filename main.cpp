#include <iostream>
#include <iomanip>
#include <stdio.h> // c
#include <stdlib.h> // srand rand
#include <time.h> // time for srand
// my libraries
#include "headers/bet.h"
#include "headers/symb.h"
#include "headers/generateResults.h"
#include "headers/inputReaders.h"

using namespace std;

int const CURRENT_MONEY_START = 100;

void sorting (int size, char slotSymbols[]);

int main () {
    float moneyStart = CURRENT_MONEY_START;
    float currentMoney = CURRENT_MONEY_START;
    float currentBet = 0.0f;
    char keepPlaying = checkBetterMoney(currentMoney);
    char slotSymbols[] = { '$', '#', '#', '@', '@', '@' };
    char sortingSymbols[] = { '$', '#', '@' };
    char currentSymbols[AMOUNT_SYMBOLS];
    float betValues[] = { 0.25f, 0.50f, 1.00f };
    float lastGain = 0.0f;
    int lastMultiplier = 0;
    int arraySizeSlSy = sizeof(slotSymbols) / sizeof(slotSymbols[0]);
    int arraySizeBeVa = sizeof(betValues) / sizeof(betValues[0]);
    int arraySizeSoSy = sizeof(sortingSymbols) / sizeof(sortingSymbols[0]);
    string result = "";

    //sorting(arraySizeSoSy, sortingSymbols);

    while (toupper(keepPlaying) == 'Y') {
        // place the bet and subtract money
        currentBet = placeBet(arraySizeBeVa, betValues, currentMoney);
        currentMoney -= currentBet;

        // generate and manipulate bet result
        generateBetResult(arraySizeSlSy, slotSymbols, currentSymbols);
        result = checkBetGenerateResult(currentSymbols);
        lastMultiplier = findMultiplier(result);
        lastGain = calculateBetResult(currentBet, lastMultiplier);

        // show result and ask for play again
        currentMoney += lastGain;
        showPlayResult(result, currentBet, lastGain);
        cout << "Actual Money: " << currentMoney << endl;
        keepPlaying = readCharYesNo("\nDo you want to continue (Y/N)?");
        showFinalResult(keepPlaying, moneyStart, currentMoney);
    }

    return 0;
}


void sorting (int size, char slotSymbols[]) {
    char input;


    while (input != 'e') {
        cout << "\r" << slotSymbols[rand()%size] << flush;
//        i++;
//        if (i == size) i = 0;
    }
}


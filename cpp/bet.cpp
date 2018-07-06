//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/bet.h"
#include "../headers/symb.h"
#include "../headers/inputReaders.h"
#include "../headers/screen.h"

char checkBetterMoney (int money) {
    return money >= 0 ? 'Y' : 'N';
}

string checkBetGenerateResult (char current[]) {
    int moneySymbCount = 0, hashTagSymbCount = 0;
    char moneySymb = '$', hashTagSymb = '#';
    string returnS;

    for (int i = 0; i < AMOUNT_SYMBOLS; i++) {
        if (current[i] == moneySymb) moneySymbCount++;
        if (current[i] == hashTagSymb) hashTagSymbCount++;
    }

    if (moneySymbCount <= 1 && hashTagSymbCount <= 1) {
        return "L";
    } else {
        if (moneySymbCount >= 2) {
            returnS = checkSymbAmount(moneySymb, moneySymbCount);
        } else {
            returnS = checkSymbAmount(hashTagSymb, hashTagSymbCount);
        }
    }

    return returnS;
}

float calculateBetResult (float bet, int multiplier) {
    return bet * multiplier;
}

float placeBet (int size, float values[], float money) {
    int amount = 0;
    float bet = 0;
    string notEnoughMoney = "Bet to big!! Try again.";
    string currentBet = "Your bet will bet $ ";

    do {
        do {
            bet = 0;
            clearBetScreen (12, (24/2));
            for (int i = 0; i < size; i++) {
                amount = readIntPositiveNumber("", (12+i), (24/2)-36);
                bet += values[i] * amount;
            }

            if (bet > money) setMsgOnPosition(notEnoughMoney, 18, (24/2)-10);
        } while (bet > money);
        string numBet = setRealNumberPrecision(bet, 2);
        setMsgOnPosition(currentBet+numBet, 18, (24/2)-10);
    } while (toupper(confirmBet(19, (24/2)-10)) == 'N');

    return bet;
}

char confirmBet (short width, short height) {
    return readCharYesNo("Confirm bet? (Y/N)", width, height);
}

void generateBetResult (int size, char slotSymbols[], char current[]) {
    srand(time(NULL)); // user later for better rand()
    string symb;
    int jumpSlots = 0;
    for (int i = 0; i < AMOUNT_SYMBOLS; i++) {
        current[i] = slotSymbols[rand()%size];
        symb = string(1, current[i]);
        setMsgOnPosition(symb, 9, (24/2)+(42+jumpSlots));
        jumpSlots += 6;
    }
}


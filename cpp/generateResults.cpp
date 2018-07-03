//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/generateResults.h"

void showPlayResult (string result, float& bet, float gain) {
    cout << endl;
    if (result == "L") {
        cout << "Oops!! It was not this time ..." << endl;
    } else {
        cout << "Congratulations!! You earned $" << gain << endl;
    }
}

void showFinalResult (char& keep, float& startMoney, float& finalMoney) {
    if (toupper(keep) == 'Y') return;
    cout << "You started the game with $" << startMoney << ". And finished with $" << finalMoney << endl;
    cout << (finalMoney - startMoney > 0 ? "Congratulations!! You earned $" : "Oops!! You loss $") << startMoney - finalMoney << endl;
}


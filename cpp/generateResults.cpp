//
// Created by Douglas Martins on 01/07/2018.
//
#include "../headers/generateResults.h"
#include "../headers/screen.h"

string showPlayResult (string result, float gain) {
    //cout << endl;
    if (result == "L") { // start here tomorrow
        return "Oops!! It was not this time ...          ";
    } else {
        string numGain = setRealNumberPrecision(gain, 2);
        return "Congratulations!! You earned $ "+numGain;
    }
}

void showFinalResult (char keep, float startMoney, float finalMoney) {
    if (toupper(keep) == 'Y') return;
    cout << "You started the game with $" << startMoney << ". And finished with $" << finalMoney << endl;
    cout << (finalMoney - startMoney > 0 ? "Congratulations!! You earned $" : "Oops!! You loss $") << startMoney - finalMoney << endl;
}


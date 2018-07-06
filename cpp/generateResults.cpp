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

void showFinalResult (char keep, float startMoney, float finalMoney, short width, short height) {
    if (toupper(keep) == 'Y') return;
    cleanScreen();
    string moneyDif = setRealNumberPrecision((finalMoney-startMoney), 2);
    string results = "You started the game with $"+setRealNumberPrecision(startMoney, 2)+".";
    string results2 = "And finished with $"+setRealNumberPrecision(finalMoney, 2);
    //string absMoneyDif = setRealNumberPrecision(abs((finalMoney-startMoney)), 2); // aqui porra
    string gains = (finalMoney - startMoney > 0 ? "Congratulations!! You earned $" : "Oops!! You loss $")+moneyDif+".";

    setMsgOnPosition(results, (width/2), (height/2)+25);
    setMsgOnPosition(results2, (width/2)+1, (height/2)+30);
    setMsgOnPosition(gains, (width/2)+3, (height/2)+30);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int die();
void playGame();

int amount = 100;

int main() {
    char ans;
    bool done = false;
    srand(time(0));  // Seed the random number generator

    while (!done) {
        if (amount > 0) {
            playGame();
            cout << "Play again (y/n)? ";
            cin >> ans;
            if (ans == 'n' || ans == 'N') done = true;
        }
        else {
            cout << "You are out of credits - game over\n";
            done = true;
        }
    }
    return 0;
}

int die() {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int sum = die1 + die2;
    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
    return sum;
}

void playGame() {
    int wager;
    cout << "You have " << amount << " credits. How much do you want to wager? ";
    cin >> wager;

    while (wager > amount) {
        cout << "Your wager exceeds your balance. Try again.\n";
        cout << "How much do you wager? ";
        cin >> wager;
    }

    int sum = die();

    if (sum == 7 || sum == 11) {
        cout << "Player wins!" << endl;
        amount += wager;
        cout << "You won " << wager << " credits. Your new balance is " << amount << " credits." << endl;
    }
    else if (sum == 2 || sum == 3 || sum == 12) {
        cout << "Player loses (craps)!" << endl;
        amount -= wager;
        cout << "You lost " << wager << " credits. Your new balance is " << amount << " credits." << endl;
    }
    else {
        int point = sum;
        cout << "Point is " << point << endl;

        // Keep rolling until player makes point or rolls a 7
        do {
            sum = die();
        } while (sum != point && sum != 7);

        if (sum == point) {
            cout << "Player wins!" << endl;
            amount += wager;
            cout << "You won " << wager << " credits. Your new balance is " << amount << " credits." << endl;
        }
        else {
            cout << "Player loses!" << endl;
            amount -= wager;
            cout << "You lost " << wager << " credits. Your new balance is " << amount << " credits." << endl;
        }
    }
}


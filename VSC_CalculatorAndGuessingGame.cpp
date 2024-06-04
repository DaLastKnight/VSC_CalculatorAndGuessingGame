// CalculatorAndGuessGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

// Intro to application will start first for choosing a program
// If digits 1 or 2 are inputted, they will start the calculator and guessing game respectively
// All other digits will yield the end to the program
// There is a weird bug where if an alphabet is inputted, the console starts printing out
// "Invalid answer" and "Would you like to continue using the program?" infinitely
// 148 Lines of code :)
// https://stackoverflow.com/questions/7560114/random-number-c-in-some-range Random number generator code I referred to

void app(int num) {
    char continueApp;
    bool usingApp = true;
    while (usingApp) {
        if (num == 1) {
            cout << "Would you like to use a calculator or play a guessing game?" << "\n";
            int appNum;
            cin >> appNum;
             

            switch (appNum) {
            case 1: {
                int num1;
                int num2;
                char op;
                int total;
                char continueCalculator;
                bool usingCalculator = true;

                // Variables used for calculator

                while (usingCalculator) {
                    cout << "Enter 1st Number" << "\n";
                    cin >> num1;
                    cout << "Enter operator" << "\n";
                    cin >> op;
                    cout << "Enter 2nd Number" << "\n";
                    cin >> num2;

                    // User input

                    if (op == '+') {
                        total = num1 + num2;
                        cout << total << "\n";
                    }
                    else if (op == '-') {
                        total = num1 - num2;
                        cout << total << "\n";
                    }
                    else if (op == '*') {
                        total = num1 * num2;
                        cout << total << "\n";
                    }
                    else if (op == '/') {
                        total = num1 / num2;
                        cout << total << "\n";
                    }
                    else {
                        cout << "Invalid operator" << "\n";
                    }

                    /*
                    The calculator function : Can produce a result of 2 numbers that use an operation that
                    is either: a+b , a-b , a*b , a/b
                    */

                    cout << "Would you like to continue using the calculator?" << "\n";
                    cin >> continueCalculator;

                    while (continueCalculator != 'Y' && continueCalculator != 'N') {
                        cout << "Invalid answer" << "\n";
                        cout << "Would you like to continue using the calculator?" << "\n";
                        cin >> continueCalculator;
                    }

                    if (continueCalculator == 'N') {
                        usingCalculator = false;
                    }
                }
                break; // User decides whether they want to continue using the calculator or not
            } // Note to prevent future confusion: This scope refers to case 1 aka the calculator :)
            case 2: {
                int secretNum;
                int guessNum;
                int randomCycle = 0;
                int guessCount = 3;
                char continueGame;
                bool playingGame = true;

                
                // This randomises the secret number everytime case 2 aka guessing game starts
                while (playingGame) {
                    int randomCycle = 0;
                    int guessCount = 3;

                    // I declare the variables here again to ensure that everything is reset properly before the game starts

                    do {
                        srand(time(0));
                        random_device rd; // Obtains a random number from a hardware
                        mt19937 gen(rd()); // Seed the generator
                        uniform_int_distribution<> distr(1, 10); // Generates a number within the specified range
                        secretNum = distr(gen);
                        randomCycle++;
                    } while (randomCycle != 1); // This code ensures that the number isn't generated again midway the game

                    do {
                        cout << "Guess the number" << "\n";
                        cin >> guessNum;
                        guessCount--;
                    } while (guessCount > 0 && guessNum != secretNum); // User guesses a number until they run out of guesses or guess the right number

                    if (guessNum == secretNum && guessCount > 0) {
                    cout << "You win!" << "\n";
                    }
                    else if (guessNum != secretNum && guessCount <= 0) {
                    cout << "You lose!" << "\n";
                    }

                
                    cout << "Would you like to continue playing the guessing game?" << "\n";
                        cin >> continueGame;

                        while (continueGame != 'Y' && continueGame != 'N') {
                            cout << "Invalid answer" << "\n";
                            cout << "Would you like to continue playing the guessing game?" << "\n";
                            cin >> continueGame;
                        }

                        if (continueGame == 'N') {
                        playingGame = false;
                        }
                    }
                    break; // User decides whether they want to continue playing the game or not
                




            } // Note to prevent future confusion: This scope refers to case 2 aka the guessing game :)

            } // This scope refers to the entire switch statement :)

            cout << "Would you like to continue using the program?" << "\n";
            cin >> continueApp;

            while (continueApp != 'Y' && continueApp != 'N') {
                cout << "Invalid answer" << "\n";
                cout << "Would you like to continue using the program?" << "\n";
                cin >> continueApp;
            }
            
            if (continueApp == 'N') {
                usingApp = false;
            }
        }
        // User decides whether they want to continue using the app or not
    }
}

int main()
{
    app(1);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

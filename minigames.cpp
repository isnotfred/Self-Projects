#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

//Function Declarations
void playRPS();
char getPlayerChoice();
void showPlayerChoice(char playerChoice);
char getComputerChoice();
void RPS_results(char playerChoice, char computerChoice);

void playGTN();
int chooseDifficulty();
void easyModeGTN();
void hardModeGTN();

void playQM();
void easyModeQM();
void hardModeQM();
char getOperation();

//Main Function - Select Game
int main () {
    int gameChoice; 
    do {
    cout << "*******************************\n";
    cout << "Welcome to Minigames!\n";
    cout << "*******************************\n";
    cout << "Choose a game:\n";
    cout << "1 Rock-Paper-Scissors\n";
    cout << "2 Guess the Number\n";
    cout << "3 Quick Math\n";
    cout << "4 Exit\n";
    cout << "*******************************\n";
    cin >> gameChoice;

        switch (gameChoice)
        {
        case 1:
            cout << "*******************************\n";
            cout << "Welcome to Rock-Paper-Scissors!\n";
            cout << "*******************************\n";
            playRPS();
            break;
        case 2:
            cout << "*******************************\n";
            cout << "Welcome to Guess the Number!\n";
            playGTN();
            break;
        case 3:
            cout << "*******************************\n";
            cout << "Welcome to Quick Math!\n";
            playQM();
            break;
        case 4:
            cout << "*******************************\n";
            cout << "Thank you for playing\n";
            cout << "*******************************\n";
            break;        
        default:
            cout << "Invalid number!\n";
            break;
        }
    } while(gameChoice !=4);

}
//Function to start Rock-Paper-Scissors
void playRPS() {
    char playerChoice, computerChoice;
    char playAgain;
    do {
        playerChoice = getPlayerChoice();
        showPlayerChoice(playerChoice);
        computerChoice = getComputerChoice();
        cout << "*******************************\n";
        RPS_results(playerChoice, computerChoice);

        cout << "*******************************\n";
        cout << "Play again? (y/n)\n";
        cout << "*******************************\n";
        cin >> playAgain;

        switch (playAgain) {
        case 'y':
            break;
        case 'n':
            break;
        default:
            cout << "Invalid input!\n";
            break;
        }
    } while(playAgain != 'n');
}
//Prompt player to input (rock/paper/scissors)
char getPlayerChoice() {
    char playerChoice;
    do {
        cout << "Enter your choice - r/p/s: ";
        cin >> playerChoice;
        if (playerChoice != 'r' && playerChoice != 'p' && playerChoice != 's') {
            cout << "Invalid! Please enter r/p/s.\n";
            cin.clear();
        }
    } while (playerChoice != 'r' && playerChoice != 'p' && playerChoice != 's');
    return playerChoice;
}
//Print player input
void showPlayerChoice(char playerChoice) {
    switch (playerChoice) {
    case 'r':
        cout << "Your choice was Rock.\n"; 
        break;
    case 'p':
        cout << "Your choice was Paper.\n";
        break;    
    case 's':
        cout << "Your choice was Scissors.\n";
        break;
    }
}
//Generate random computer choice (rock/paper/scissors)
char getComputerChoice() {
    srand(time(NULL));
    int ranNum = rand() % 3 + 1;
    char computerChoice;
    if (ranNum == 1) {
        cout << "Computer chose Rock.\n";
        computerChoice = 'r';
    }
    else if (ranNum == 2) {
        cout << "Computer chose Paper.\n";
        computerChoice = 'p';
    }
    else if (ranNum == 3) {
        cout << "Computer chose Scissors.\n";
        computerChoice = 's';
    }
    return computerChoice;
}
//Display game winner
void RPS_results(char playerChoice, char computerChoice) {
    switch (playerChoice) {
    case 'r':
        if (computerChoice == 'r') 
            cout << "It's a tie.\n";
        else if (computerChoice == 'p')
            cout << "You lost.\n";
        else if (computerChoice == 's')
            cout << "You won!\n";
        break;
    case 'p':
        if (computerChoice == 'r') 
            cout << "You won!\n";
        else if (computerChoice == 'p')
            cout << "It's a tie.\n";
        else if (computerChoice == 's')
            cout << "You lost.\n";
        break;
    case 's':
        if (computerChoice == 'r') 
            cout << "You lost.\n";
        else if (computerChoice == 'p')
            cout << "You won!\n";
        else if (computerChoice == 's')
            cout << "It's a tie.\n";
        break;
    }
}
//Function to start Guess the Number (GTN)
void playGTN() {
    int difficulty = chooseDifficulty();
    char playAgain;
    do {
        if (difficulty == 1) {
            cout << "Start\n";
            easyModeGTN();
        } else if (difficulty == 2) {
            cout << "Start\n";
            hardModeGTN();
        } else if (difficulty == 3) {
            break;
        }
        cout << "*******************************\n";
        cout << "Play again? (y/n)\n";
        cout << "*******************************\n";
        cin >> playAgain;

        switch (playAgain) {
        case 'y':
            break;
        case 'n':
            break;
        default:
            cout << "Invalid input!\n";
            break;
        }
    } while(playAgain != 'n');
}
//Prompt player to choose difficulty
int chooseDifficulty() {
    int difficulty;
    do {
        cout << "Choose difficulty:\n";
        cout << "*******************************\n";
        cout << "1 Easy\n";
        cout << "2 Hard\n";
        cout << "3 Go back\n";
        cout << "*******************************\n";
        cin >> difficulty;

        if (difficulty != 1 && difficulty != 2 && difficulty != 3)
            cout << "Invalid input!\n";
        
    } while(difficulty != 1 && difficulty != 2 && difficulty != 3);
    return difficulty;
}
//Start GTN Easy Mode
void easyModeGTN() {
    int guess;
    int tries = 0;
    srand(time(NULL));
    int ranNum = rand() % 10 + 1;

    do {
        cout << "Guess the number (1-10): ";
        if (cin >> guess) {
            if (guess == ranNum) {
                cout << "You guessed the number!\n";
                cout << "# of tries: " << tries + 1 << "\n";
            } else if (guess > ranNum) {
                cout << "Too high!\n";
                tries++;
            }
            else {
                cout << "Too low!\n";
                tries++;
            }
        } else
            cout << "Invalid input!\n";
    } while(guess != ranNum);
}
//Start GTN Hard Mode
void hardModeGTN() {
    int guess;
    int tries = 0;
    srand(time(NULL));
    int ranNum = rand() % 100 + 1;

    do {
        cout << "Guess the number (1-100): ";
        if (cin >> guess) {
            if (guess == ranNum) {
                cout << "You guessed the number!\n";
                cout << "# of tries: " << tries + 1 << "\n";
            } else if (guess > ranNum) {
                cout << "Too high!\n";
                tries++;
            }
            else {
                cout << "Too low!\n";
                tries++;
            }
        } else
            cout << "Invalid input!\n";
    } while(guess != ranNum);
}
//Function to start Quick Math (QM)
void playQM() {
    int difficulty = chooseDifficulty();
    char playAgain;
    do {
        if (difficulty == 1) {
            cout << "Start\n";
            auto startTime = steady_clock::now();
            easyModeQM();
            auto endTime = steady_clock::now();
            auto elapsedTime = duration_cast<seconds>(endTime - startTime);
            cout << "Finished in " << elapsedTime.count() << " seconds.\n";
        } else if (difficulty == 2) {
            cout << "Start\n";
            auto startTime = steady_clock::now();
            hardModeQM();
            auto endTime = steady_clock::now();
            auto elapsedTime = duration_cast<seconds>(endTime - startTime);
            cout << "Finished in " << elapsedTime.count() << " seconds.\n";
        } else if (difficulty == 3) {
            break;
        }
        cout << "*******************************\n";
        cout << "Play again? (y/n)\n";
        cout << "*******************************\n";
        cin >> playAgain;

        switch (playAgain) {
        case 'y':
            break;
        case 'n':
            break;
        default:
            cout << "Invalid input!\n";
            break;
        }
    } while(playAgain != 'n');
}
//Generate random operation for QM
char getOperation() {
    char op;
    srand(time(NULL));
    int ranNum = rand() % 2 + 1;

    if (ranNum == 1) op = '+';
    else if (ranNum == 2) op = '*';

    return op;
}
//Start QM Easy Mode
void easyModeQM() {
    char op;
    int ans, correctAns, score = 0;

    for (int i = 1; i <= 5; i++) {
        char op = getOperation();
        srand(time(NULL));
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;
        
        if (op == '+')
            correctAns = num1 + num2;
        else if (op == '*')
            correctAns = num1 * num2;

        cout << num1 << " " << op << " " << num2 << " = ";
        cin >> ans;

        if (cin.fail()) {
            cin.clear();
            continue;
        }
        if (ans == correctAns)
            score++;
    }
    cout << "You got " << score << "/5!\n";
}
//Start QM Hard Mode
void hardModeQM() {
    char op;
    int ans, correctAns, score = 0;

    for (int i = 1; i <= 5; i++) {
        char op = getOperation();
        srand(time(NULL));
        int num1 = rand() % 20 + 1;
        int num2 = rand() % 20 + 1;
        
        if (op == '+')
            correctAns = num1 + num2;
        else if (op == '*')
            correctAns = num1 * num2;

        cout << num1 << " " << op << " " << num2 << " = ";
        cin >> ans;

        if (cin.fail()) {
            cin.clear();
            continue;
        }
        if (ans == correctAns)
            score++;
    }
    cout << "You got " << score << "/5!\n";
}

#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
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

void playTicTacToe();
void drawBoard(char *spaces);
bool checkFirst();
void getPlayerMove(char *spaces, char player);
void getComputerMove(char *spaces, char player);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

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
        cout << "4 Tic-Tac-Toe\n";
        cout << "5 Exit\n";
        cout << "*******************************\n";

        cin >> gameChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }

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
            cout << "Welcome to Tic-Tac-Toe!\n";
            cout << "*******************************\n";
            playTicTacToe();
            break;  
        case 5:
            cout << "*******************************\n";
            cout << "Thank you for playing\n";
            cout << "*******************************\n";
            break;        
        default:
            cout << "Invalid input!\n";
            break;
        }
    } while(cin.fail() || gameChoice != 5);
    return 0;
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
    } while (playAgain != 'n');
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
            cin.ignore(1000, '\n');
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
    srand(time(0));
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
        } 
        else if (difficulty == 2) {
            cout << "Start\n";
            hardModeGTN();
        } 
        else if (difficulty == 3) {
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
    } while (playAgain == 'y');
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
    } while (guess != ranNum);
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
    } while (guess != ranNum);
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
    } while (playAgain == 'y');
}
//Generates a random operation for QM
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
            cin.ignore(1000, '\n');
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
        int num1 = rand() % 10 + 11;
        int num2 = rand() % 10 + 11;
        
        if (op == '+')
            correctAns = num1 + num2;
        else if (op == '*')
            correctAns = num1 * num2;

        cout << num1 << " " << op << " " << num2 << " = ";
        cin >> ans;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (ans == correctAns)
            score++;
    }
    cout << "You got " << score << "/5!\n";
}
//Function to start Tic-Tac-Toe
void playTicTacToe() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player, computer;
    bool playerFirst = checkFirst();
    char playAgain;
    int sizeSpaces = sizeof(spaces)/sizeof(spaces[0]);

    do {
        bool running = true;
        if (playerFirst == true) {
            player = 'O';
            computer = 'X'; 

            drawBoard(spaces);
            do {
                cout << "*******************************\n";
                cout << "Player's turn! (" << player << ")\n";
                getPlayerMove(spaces, player);
                cout << "*******************************\n";
                drawBoard(spaces);
                cout << "*******************************\n";
                if (checkWinner(spaces, player, computer)) {
                    running = false;
                    break;
                }
                else if (checkTie(spaces)) {
                    running = false;
                    break;
                }
                cout << "Computer's turn! (" << computer << ")\n";
                cout << "*******************************\n";
                getComputerMove(spaces, computer);
                drawBoard(spaces);
                if (checkWinner(spaces, player, computer)) {
                    running = false;
                    break;
                }
                else if (checkTie(spaces)) {
                    running = false;
                    break;
                }
            } while (running);
        } 
        else {
            player = 'X';
            computer = 'O';

            do {
                cout << "Computer's turn! (" << computer << ")\n";
                getComputerMove(spaces, computer);
                cout << "*******************************\n";
                drawBoard(spaces);
                cout << "*******************************\n";
                if (checkWinner(spaces, player, computer)) {
                    running = false;
                    break;
                }
                if (checkTie(spaces)) {
                    running = false;
                    break;
                }
                cout << "Player's turn! (" << player << ")\n";
                getPlayerMove(spaces, player);
                cout << "*******************************\n";
                drawBoard(spaces);
                cout << "*******************************\n";
                if (checkWinner(spaces, player, computer)) {
                    running = false;
                    break;
                }
                if (checkTie(spaces)) {
                    running = false;
                    break;
                }
            } while (running);  
        }
        cout << "*******************************\n";
        cout << "Play again? (y/n)\n";
        cout << "*******************************\n";
        cin >> playAgain;

        switch (playAgain) {
        case 'y':
            for (int i = 0; i < sizeSpaces; i++) {
                spaces[i] = ' ';
            }
            break;
        case 'n':
            for (int i = 0; i < sizeSpaces; i++) {
                spaces[i] = ' ';
            }
            break;
        default:
            cout << "Invalid input!\n";
            break;
        }        
    } while (playAgain == 'y');
}
//Update and draw the board for Tic-Tac-Toe
void drawBoard(char *spaces) {
    cout << "1      |2      |3      " << '\n';
    cout << "   " << spaces[0] << "   |   " << spaces[1] << "   |   " << spaces[2] << "   " << '\n';
    cout << "_______|_______|_______" << '\n';
    cout << "4      |5      |6      " << '\n';
    cout << "   " << spaces[3] << "   |   " << spaces[4] << "   |   " << spaces[5] << "   " << '\n';
    cout << "_______|_______|_______" << '\n';   
    cout << "7      |8      |9      " << '\n';  
    cout << "   " << spaces[6] << "   |   " << spaces[7] << "   |   " << spaces[8] << "   " << '\n'; 
    cout << "       |       |       " << '\n';
}
//Check first player (player/computer)
bool checkFirst() {
    srand(time(0));
    int playerFirst = rand() % 2;

    if (playerFirst == 0) return true;
    else return false;
}
//Prompt player to input their move
void getPlayerMove(char *spaces, char player) {
    int number;
    do {
        cout << "Enter number where you want to place (1-9): ";
        cin >> number;
        number--;

        if (spaces[number] == ' ' && number >= 0 && number <= 8) {
            spaces[number] = player;
            break;
        } else if (cin.fail() || number < 0 || number > 8) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(1000, '\n');
        } else {
        cout << "Space is occupied!\n";
        }
    } while (spaces[number] != ' ' || number < 0 || number > 8);
}
//Randomly generate computer's move
void getComputerMove(char *spaces, char computer) {
    int number;
    srand(time(0));
    while (true) {
        int number = rand() % 9;

        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}
//Check if there is a winner after a move
bool checkWinner(char *spaces, char player, char computer) {
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
        spaces[0] == player ? cout << "Player Wins!\n" : cout << "Computer Wins!\n";
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
        spaces[3] == player ? cout << "Player Wins!\n" : cout << "Computer Wins!\n";
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
        spaces[6] == player ? cout << "Player Wins!\n" : cout << "Computer Wins!\n";
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
        spaces[0] == player ? cout << "Player Wins!\n" : cout << "Computer Wins!\n";
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
        spaces[1] == player ? cout << "Player Wins!\n" : cout << "Computer Wins!\n";
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
        spaces[2] == player ? cout << "Player Wins!\n" : cout << "Computer Wins!\n";
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
        spaces[0] == player ? cout << "Player Wins!\n" : cout << "Computer Wins!\n";
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
        spaces[2] == player ? cout << "Player Wins!\n" : cout << "Computer Wins!\n";  
    else
        return false;
    return true;
    cout << "*******************************\n";
}
//Check if all spots have been filled which results in a tie
bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ')
            return false;
    }
    cout << "It's a tie!\n";
    return true;
}

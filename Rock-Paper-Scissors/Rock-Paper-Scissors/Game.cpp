#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

char playGame(int &round, int &playerPoints, int &computerPoints);
void showResult(int playerPoints, int computerPoints);
char getPlayerChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer, int &playerPoints, int &computerPoints);

int main()
{
    int round = 0;
    int playerPoints = 0;
    int computerPoints = 0;

    for (int i = 0; i < 3; i++) {
        playGame(round, playerPoints, computerPoints);
    }
   
    if (playerPoints > computerPoints) {
        std::cout << "You win the game!";
    }
    else if (playerPoints < computerPoints) {
        std::cout << "You lose the game!";
    }
    else {
        std::cout << "Tie!";
    }
   
    showResult(playerPoints, computerPoints);

    return 0;
}

char playGame(int &round, int &playerPoints, int &computerPoints) {
    char player;
    char computer;

    do {
        std::ostringstream title;
        title << "Welcome to round: " << round + 1 << "\nPlayer Points: " << playerPoints << "\nComputer Points: " << computerPoints;
        std::string var = title.str();

        std::cout << var << std::endl;

        player = getPlayerChoice();
        std::cout << "Your choice: ";
        showChoice(player);

        computer = getComputerChoice();
        std::cout << "Computer choice: ";
        showChoice(computer);

        chooseWinner(player, computer, playerPoints, computerPoints);
        
    } while (player != 'r' && player != 'p' && player != 's');
        
    round++;

    return player, computer;
}
void showResult(int playerPoints, int computerPoints) {
    std::ostringstream result;
    result << "\nScoreboard -> Player Points: " << playerPoints << " Computer Points: " << computerPoints;
    std::string var = result.str();
    std::cout << "\n***************************************************";
    std::cout << var << std::endl;
    std::cout << "***************************************************";
}
char getPlayerChoice()
{

    char player;
    std::cout << "Rock-Paper-Scissors Game!\n";

    do
    {
        std::cout << "Choose one the following\n";
        std::cout << "***************************\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for sicssors\n";
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}
char getComputerChoice()
{
    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num)
    {
    case 1:
        return 'r';
        break;
    case 2:
        return 'p';
        break;
    case 3:
        return 's';
        break;
    default:
        break;
    }

    return num;
}
void showChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        std::cout << "Rock\n";
        break;
    case 'p':
        std::cout << "Paper\n";
        break;
    case 's':
        std::cout << "Scissors\n";
        break;
    default:
        break;
    }
}
void chooseWinner(char player, char computer, int &playerPoints, int &computerPoints)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            std::cout << "It's a tie!\n";
        }
        else if (computer == 'p')
        {
            std::cout << "You lose!\n";
            computerPoints++;
        }
        else
        {
            std::cout << "You win!\n";
            playerPoints++;
        }
        break;
    case 'p':
        if (computer == 'p')
        {
            std::cout << "It's a tie!\n";
        }
        else if (computer == 's')
        {
            std::cout << "You lose!\n";
            computerPoints++;
        }
        else
        {
            std::cout << "You win!\n";
            playerPoints++;
        }
        break;
    case 's':
        if (computer == 's')
        {
            std::cout << "It's a tie!\n";
        }
        else if (computer == 'r')
        {
            std::cout << "You lose!\n";
            computerPoints++;
        }
        else
        {
            std::cout << "You win!\n";
            playerPoints++;
        }
        break;
    }
}
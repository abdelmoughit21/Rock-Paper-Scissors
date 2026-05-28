#include <iostream>
using namespace std;

enum enStonePaperScissor { Stone = 1, Paper = 2, Scissor = 3 };

struct stGlobalResult {

    int GameRound , PlayerWonTimes , ComputerWonTimes , DrawTimes = 0;

};

enStonePaperScissor GetPlayerChoice(string message) {

    int num;

    cout << message;
    cin >> num;

    while (num < 1 || num > 3) {

        cout << message;
        cin >> num;

    }

    return (enStonePaperScissor)num;

}

string getPlayerChoiceName(enStonePaperScissor PlayerChoice) {

    switch (PlayerChoice) {
        
        case enStonePaperScissor::Paper:
           return "Paper";
        case enStonePaperScissor::Scissor:
            return "Scissor";
        case enStonePaperScissor::Stone:
            return "Stone";

    }

}

int PositiveNumber(string message) {

    int num = 0;

    cout << message;
    cin >> num;

    while (num < 0) {

        cout << message;
        cin >> num;

    }

    return num;

}

int GetRandomNumber(int from, int to) {

    int randNum = rand() % (to - from + 1) + from;

    return randNum;

}

void ResetScreen() {

    system("cls");
    system("color 0F");

}

void ScreenColor(string winner) {

    if (winner == "Player") {

        system("color 2F");

    }
    else if (winner == "Computer") {

        system("color 4F");
        cout << "\a";

    }
    else {

        system("color 6F");

    }

}

string getTheFinalWinner(int PlayerWonTimes, int ComputerWonTimes, int DrawTimes) {

    if (PlayerWonTimes > ComputerWonTimes)
        return "Player";
    else if (ComputerWonTimes > PlayerWonTimes)
        return "Computer";
    else
        return "No Winner";

}

string CheckWhoWin(enStonePaperScissor PlayerChoice, enStonePaperScissor ComputerChoice) {

    if (PlayerChoice == ComputerChoice) {

        return "No Winner";

    }
    else if (PlayerChoice == enStonePaperScissor::Paper && ComputerChoice == enStonePaperScissor::Stone) {

        return "Player";

    }
    else if (PlayerChoice == enStonePaperScissor::Stone && ComputerChoice == enStonePaperScissor::Paper) {

        return "Computer";

    }
    else if (PlayerChoice == enStonePaperScissor::Scissor && ComputerChoice == enStonePaperScissor::Paper) {

        return "Player";

    }
    else if (PlayerChoice == enStonePaperScissor::Paper && ComputerChoice == enStonePaperScissor::Scissor) {

        return "Computer";

    }
    else if (PlayerChoice == enStonePaperScissor::Stone && ComputerChoice == enStonePaperScissor::Scissor) {

        return "Player";

    }
    else if (PlayerChoice == enStonePaperScissor::Scissor && ComputerChoice == enStonePaperScissor::Stone) {

        return "Computer";

    }

}

void RoundResult(int Round, enStonePaperScissor PlayerChoice, enStonePaperScissor ComputerChoice, string winner) {

    cout << "--------------------- Round [" << Round << "] ---------------------" << endl << endl;
    cout << "Player 1 choice : " << getPlayerChoiceName(PlayerChoice) << endl;
    cout << "Computer choice : " << getPlayerChoiceName(ComputerChoice) << endl;
    cout << "Round Winner : " << winner << endl << endl;
    cout << "---------------------------------------------------" << endl << endl;

    ScreenColor(winner);

}

void PlayRound(int Rounds , int &PlayerWonTimes , int &ComputerWonTimes , int &DrawTimes) {

    for (int i = 1; i <= Rounds; i++) {

        enStonePaperScissor PlayerChoice = GetPlayerChoice("Your Choice : [1]:Stone, [2]:Paper, [3]:Scissor ? ");
        enStonePaperScissor ComputerChoice = (enStonePaperScissor)GetRandomNumber(1, 3);

        string winner = CheckWhoWin(PlayerChoice, ComputerChoice);

        if (winner == "Player") {

            PlayerWonTimes++;

        }
        else if (winner == "Computer") {

            ComputerWonTimes++;

        }
        else if (winner == "No Winner") {

            DrawTimes++;

        }

        RoundResult(i, PlayerChoice, ComputerChoice, winner);

    }

}

void StartPlaying (int &Rounds, int &PlayerWonTimes, int &ComputerWonTimes, int &DrawTimes) {

    Rounds = PositiveNumber("Enter How many rounds do you wanna play 1 to 10 : ");

    PlayRound(Rounds, PlayerWonTimes, ComputerWonTimes, DrawTimes);
    
}

void GameResult(int Rounds, int PlayerWonTimes, int ComputerWonTimes, int DrawTimes) {

    string FinalWinner = getTheFinalWinner(PlayerWonTimes,ComputerWonTimes,DrawTimes);

    cout << "\t\t" << "----------------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t" << "                                 ++G A M E   O V E R++                                  " << endl << endl;
    cout << "\t\t" << "----------------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t" << "---------------------------------- [ Game Results ] ------------------------------------" << endl << endl;
    cout << "\t\t" << "Game Rounds            : " << Rounds << endl;
    cout << "\t\t" << "Player 1 won times     : " << PlayerWonTimes << endl;
    cout << "\t\t" << "Computer won times     : " << ComputerWonTimes << endl;
    cout << "\t\t" << "Draw times             : " << DrawTimes << endl;
    cout << "\t\t" << "Final Winner           : " << FinalWinner << endl << endl;
    cout << "\t\t" << "----------------------------------------------------------------------------------------" << endl << endl;

    ScreenColor(FinalWinner);

}

void StartGame() { 

    char answer ;

    do {

        int Rounds = 0, PlayerWonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

        ResetScreen();

        StartPlaying(Rounds, PlayerWonTimes, ComputerWonTimes, DrawTimes);
        GameResult(Rounds, PlayerWonTimes, ComputerWonTimes, DrawTimes);

        cout << "Do you want to play again ? Y/N ? ";
        cin >> answer;

    } while (answer == 'Y' || answer == 'y');

}

int main()
{

    srand((unsigned)time(NULL));
    
    StartGame();

    return 0;
}

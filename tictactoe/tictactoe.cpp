#include <iostream>
using namespace std;

class TicTacToe {
private:
    char space[3][3];
    int playerXScore;
    int playerOScore;
    

public:
    TicTacToe() {
        // Initialize the space
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                space[i][j] = '-';
            }
        }

        playerXScore = 0;
        playerOScore = 0;
    }

    void displayspace() {
        // Display the current state of the space
        cout<<"     |     |  \n";
        cout<<"  "<<space[0][0]<<"  |  "<<space[0][1]<<"  |  "<<space[0][2]<<"  \n";
        cout<<"_____|_____|_____\n";
        cout<<"     |     |  \n";
        cout<<"  "<<space[1][0]<<"  |  "<<space[1][1]<<"  |  "<<space[1][2]<<"  \n";
        cout<<"_____|_____|_____\n";
        cout<<"     |     |  \n";
        cout<<"  "<<space[2][0]<<"  |  "<<space[2][1]<<"  |  "<<space[2][2]<<"  \n";
        cout<<"     |     |  \n";
    }

    bool makeMove(int row, int col, char player) {
        // Make a move on the space
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || space[row][col] != '-') {
            return false; // Invalid move
        }

        space[row][col] = player;
        return true;
    }

    bool checkWin(char player) {
        // Check for a win in rows, columns, or diagonals
        for (int i = 0; i < 3; ++i) {
            if (space[i][0] == player && space[i][1] == player && space[i][2] == player) {
                return true; // Row win
            }

            if (space[0][i] == player && space[1][i] == player && space[2][i] == player) {
                return true; // Column win
            }
        }

        if (space[0][0] == player && space[1][1] == player && space[2][2] == player) {
            return true; // Diagonal win (top-left to bottom-right)
        }

        if (space[0][2] == player && space[1][1] == player && space[2][0] == player) {
            return true; // Diagonal win (top-right to bottom-left)
        }

        return false; // No win
    }
};

int main() {

    TicTacToe game;


    char currentPlayer = 'X';

    int count = 0;
    for(int i=0;i<=9;i++)
    {
        game.displayspace();

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (game.makeMove(row, col, currentPlayer)) {
            count++;
            if (game.checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }

    }

    if(count == 9)
    {
        cout<<"Game draw !\n";
    } 

    return 0;
}

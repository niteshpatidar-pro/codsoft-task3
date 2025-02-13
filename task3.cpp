#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i < row.size() - 1) cout << " | ";
        }
        cout << "\n---------\n";
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void ticTacToe() {
    while (true) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char players[2] = {'X', 'O'};
        int currentPlayer = 0;

        while (true) {
            printBoard(board);
            int row, col;
            while (true) {
                cout << "Player " << players[currentPlayer] << ", enter row and column (0-2): ";
                cin >> row >> col;
                if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                    break;
                }
                cout << "Invalid input. Try again.\n";
            }

            board[row][col] = players[currentPlayer];
            if (checkWin(board, players[currentPlayer])) {
                printBoard(board);
                cout << "Player " << players[currentPlayer] << " wins!\n";
                break;
            }
            if (isDraw(board)) {
                printBoard(board);
                cout << "It's a draw!\n";
                break;
            }
            currentPlayer = 1 - currentPlayer;
        }

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }
}

int main() {
    ticTacToe();
    return 0;
}
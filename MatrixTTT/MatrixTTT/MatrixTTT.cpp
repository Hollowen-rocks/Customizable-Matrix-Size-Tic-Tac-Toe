#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    int rows, columns;
    char currentPlayer;

    void printBoard() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << board[i][j];
                if (j < columns - 1) cout << " | ";
            }
            cout << endl;
            if (i < rows - 1) {
                for (int j = 0; j < columns; ++j) {
                    cout << "--";
                    if (j < columns - 1) cout << "+-";
                }
                cout << endl;
            }
        }
    }

    bool checkLine(const vector<char>& line) {
        for (char cell : line) {
            if (cell != currentPlayer) return false;
        }
        return true;
    }

    bool checkDiagonals() {
        if (rows != columns) return false;

        bool diagonal1 = true, diagonal2 = true;
        for (int i = 0; i < rows; ++i) {
            if (board[i][i] != currentPlayer) diagonal1 = false;
            if (board[i][rows - 1 - i] != currentPlayer) diagonal2 = false;
        }
        return diagonal1 || diagonal2;
    }

    bool checkWinner(int row, int col) {
        vector<char> rowLine = board[row];
        vector<char> colLine(columns);
        for (int i = 0; i < rows; ++i) {
            colLine[i] = board[i][col];
        }
        return checkLine(rowLine) || checkLine(colLine) || checkDiagonals();
    }

    bool isDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

public:
    TicTacToe(int r, int c) : rows(r), columns(c), currentPlayer('X') {
        board.resize(rows, vector<char>(columns, ' '));
    }

    void playGame() {
        int moveCount = 0;
        while (true) {
            printBoard();
            int row, col;
            while (true) {
                cout << "Player " << currentPlayer << ", enter the row and column (0-" << rows - 1 << ") for your move: ";
                cin >> row >> col;
                if (cin.fail() || row < 0 || row >= rows || col < 0 || col >= columns || board[row][col] != ' ') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input or move! Please try again." << endl;
                }
                else {
                    break;
                }
            }
            board[row][col] = currentPlayer;
            moveCount++;
            if (checkWinner(row, col)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (isDraw()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
};

int main() {
    int rows, columns;
    while (true) {
        cout << "Enter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> columns;
        if (cin.fail() || rows <= 0 || columns <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Rows and columns must be positive integers." << endl;
        }
        else {
            break;
        }
    }
    TicTacToe game(rows, columns);
    game.playGame();
    return 0;
}

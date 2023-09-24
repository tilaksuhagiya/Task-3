#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
    char board[3][3];       
    string playerXName;     // Name of Player X
    string playerOName;     // Name of Player O
    char currentPlayer;     // Current player ('X' or 'O')
    bool gameWon;           // Flag to track if the game is won

public:
    TicTacToe() {
        currentPlayer = 'X';    // Start with Player X
        gameWon = false;
        initializeBoard();       // Initialize the game board
    }

    // Initialize the game board with empty spaces
    void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    // Display the current state of the board
    void displayBoard() {
        cout << "  1 2 3" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "  -+-+-" <<endl;
        }
    }

    // Check if a move is valid
    bool isMoveValid(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            return true;
        }
        return false;
    }

    // Make a move on the board
    void makeMove(int row, int col) {
        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;
        }
    }

    // Check if the current player has won
    bool checkWin() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                gameWon = true;
                return true;
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                gameWon = true;
                return true;
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            gameWon = true;
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            gameWon = true;
            return true;
        }
        return false;
    }

    // Check if the game is a draw
    bool isDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    // Switch turns between players
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Start and manage the game
    void play() {
        cout << "Welcome to Tic-Tac-Toe!" <<endl;

        cout << "Enter the name of Player X: ";
        cin >> playerXName;
        cout << "Enter the name of Player O: ";
        cin >> playerOName;

        while (!gameWon && !isDraw()) {
            displayBoard();
            int row, col;
            cout << playerXName << " (X) vs. " << playerOName << " (O)" <<endl;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Check for valid input and clear the input buffer
            if (cin.fail()) {
                cout << "Invalid input. Please enter valid numbers." <<endl;
                cin.clear();
                cin.ignore(256, '\n');
                continue;
            }

            row--; // Adjust for 0-based indexing
            col--;

            if (isMoveValid(row, col)) {
                makeMove(row, col);

                if (checkWin()) {
                    displayBoard();
                    cout << playerXName << " (" << currentPlayer << ") wins!" <<endl;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move. Try again." <<endl;
            }
        }

        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!" <<endl;
        }

        cout << "Thanks for playing!" <<endl;
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}

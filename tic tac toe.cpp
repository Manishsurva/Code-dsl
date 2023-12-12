#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Player {
public:
    virtual void makeMove(std::vector<std::vector<char>>& board) = 0;
};

class HumanPlayer : public Player {
public:
    void makeMove(std::vector<std::vector<char>>& board) override {
        int row, col;
        std::cout << "Enter your move (row and column, e.g., 1 2): ";
        std::cin >> row >> col;

        // Adjust row and column to match array indices
        row--;
        col--;

        if (isValidMove(row, col, board)) {
            board[row][col] = 'X';
        } else {
            std::cout << "Invalid move. Try again.\n";
            makeMove(board);
        }
    }

private:
    bool isValidMove(int row, int col, const std::vector<std::vector<char>>& board) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }
};

class ComputerPlayer : public Player {
public:
    void makeMove(std::vector<std::vector<char>>& board) override {
        int row, col;
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (!isValidMove(row, col, board));

        std::cout << "Computer chooses: " << row + 1 << " " << col + 1 << std::endl;
        board[row][col] = 'O';
    }

private:
    bool isValidMove(int row, int col, const std::vector<std::vector<char>>& board) const {
        return (board[row][col] == ' ');
    }
};

class Board {
public:
    Board() {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
    }

    void display() const {
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }

    bool isFull() const {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
            return true;
        }

        return false;
    }

    std::vector<std::vector<char>>& getBoard() {
        return board;
    }

private:
    std::vector<std::vector<char>> board;
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Board gameBoard;
    Player* player1 = new HumanPlayer();
    Player* player2 = new ComputerPlayer();

    Player* currentPlayer = player1;

    while (!gameBoard.isFull() && !gameBoard.checkWin()) {
        gameBoard.display();
        currentPlayer->makeMove(gameBoard.getBoard());
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    gameBoard.display();

    if (gameBoard.checkWin()) {
        std::cout << "Player wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }

    delete player1;
    delete player2;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed on the board at the given row and column
bool isSafe(vector<vector<int> > & board, int row, int col, int N) {
    // Check for queens in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check for queens in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check for queens in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N Queen's problem
bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    // Base case: If all queens are placed, return true
    if (row == N) {
        return true;
    }

    // Try placing queen in each column of the current row
    for (int col = 0; col < N; col++) {
        // Check if it's safe to place the queen at board[row][col]
        if (isSafe(board, row, col, N)) {
            // Place the queen at board[row][col]
            board[row][col] = 1;

            // Recur for the next row
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            // If placing the queen at board[row][col] doesn't lead to a solution,
            // backtrack and try placing the queen in the next column
            board[row][col] = 0;
        }
    }

    // If no column is suitable for the current row, backtrack
    return false;
}

// Function to solve the N Queen's problem and print the board
void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0, N)) {
        // Solution found, print the board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for N = " << N << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}


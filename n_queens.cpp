#include <iostream>
using namespace std;

bool can_place(int **board, int n, int row, int col) {
    int i = row - 1;
    int j_left = col - 1;
    int j_right = col + 1;

    while (i >= 0) {        if (board[i][col] == 1) { // checks condition for same column
            return false;
        }
        if (j_right < n && board[i][j_right] == 1) { // checks condition for right diagonal
            return false;
        }
        else if (j_left >= 0 && board[i][j_left] == 1) { // checks condition for left diagonal
            return false;
        }
        i--;
        j_left--;
        j_right++;
    }
    return true;
}

void n_queens(int n, int **board, int row) {
    if (row == n) {
        // n queens placed
        int *place_array = new int[n];
        int k = 0;
        cout << "The " << n << " queens can be placed as follows: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
                if (board[i][j] == 1) {
                    place_array[k++] = j;
                }
            }
            cout << endl;
        }
        cout << "The positions are: " << endl;
        for (int i = 0; i < n; i++) {
            cout << place_array[i] << " ";
        }
        cout << endl << endl;
        delete[] place_array;
        return;
    }

    // process
    for (int col = 0; col < n; col++) {
        if (can_place(board, n, row, col)) {
            board[row][col] = 1;
            n_queens(n, board, row + 1); // calling n_queens function for next row
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;

    // board initialization
    int **board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    // calling n_queens() function
    n_queens(n, board, 0); // 0th -> row

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void printBoard(int board[3][3]) {
    cout << "Current board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                cout << ".";
            } else if (board[i][j] == 1) {
                cout << "X";
            } else {
                cout << "O";
            }
        }
        cout << endl;
    }
    cout << endl;
}


void game() {
    int board[3][3] = {0};
    int player = 1; // Player 1 starts first
    int row, col;
    bool game_over = false;
    int moves = 0; // Count the number of moves made

    while (!game_over && moves < 9) {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != 0) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Place the player's mark on the board
        board[row][col] = player;
        moves++;

        printBoard(board);
        cout << "Player " << player << " made a move at (" << row << ", " << col << ")\n\n" << endl;

        // Check for a win
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                game_over = true;
                break;
            }
        }
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            game_over = true;
        }

        // Switch players
        player = (player == 1) ? 2 : 1;
    }    

    // Check the result
    if (game_over) {
        cout << "Player " << ((player == 1) ? 2 : 1) << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
    cout << "Game over!" << endl;
    cout << "Press any key to exit..." << endl;
    cout << "------------------------" << endl;
    cout << "Thank you for playing!" << endl;
    cout << "------------------------" << endl;
    cin.ignore(); // Ignore the newline character left in the input buffer
    cin.get(); // Wait for user input

}



int main()
{

    cout << "\t+-----------------------------+" << endl;
    cout << "\t|         :TicTakToe:         |" << endl;
    cout << "\t+-----------------------------+" << endl;
    cout << "\n\n";

    game();

    return 0;
}

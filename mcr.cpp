#include <iostream>
using namespace std;

// Check if any player has won
bool isWin(char game[3][3]){
    bool win = false;
    // Check rows
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
    // Check columns
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    // Check diagonals
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    return win;
}

// Display the game board
void displayBoard(char game[3][3]) {
    cout << "\n  1 2 3" << endl;
    cout << "1 " << game[0][0] << "|" << game[0][1] << "|" << game[0][2] << endl;
    cout << "  -----" << endl;
    cout << "2 " << game[1][0] << "|" << game[1][1] << "|" << game[1][2] << endl;
    cout << "  -----" << endl;
    cout << "3 " << game[2][0] << "|" << game[2][1] << "|" << game[2][2] << endl << endl;
}

int main(){
    int i, j;
    // Properly initialize the 3x3 game board with spaces
    char game[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player1 = 'X';
    char player2 = 'O';
    bool player1Turn = true; // True for player 1's turn, false for player 2's turn
    
    cout << "Tic-Tac-Toe Game" << endl;
    cout << "Player 1: X" << endl << "Player 2: O" << endl;
    cout << "Enter moves as row column (1-3 for both)" << endl;
    
    displayBoard(game);
    
    // Game loop - maximum 9 moves
    for (int n = 0; n < 9; n++){
        // Get valid move from current player
        while (true) {
            if (player1Turn)
                cout << "Player 1 (X), enter your move: ";
            else
                cout << "Player 2 (O), enter your move: ";
                
            cin >> i >> j;
            
            // Convert to 0-based index
            int row = i - 1;
            int col = j - 1;
            
            // Validate input range
            if (row < 0 || row >= 3 || col < 0 || col >= 3) {
                cout << "Invalid input! Please enter numbers between 1 and 3." << endl;
                continue;
            }
            
            // Check if cell is empty
            if (game[row][col] != ' ') {
                cout << "That cell is already occupied! Try again." << endl;
                continue;
            }
            
            // Place the marker
            if (player1Turn)
                game[row][col] = 'X';
            else
                game[row][col] = 'O';
                
            break; // Exit loop when valid move is made
        }
        
        // Display updated board
        displayBoard(game);
        
        // Check for win after at least 5 moves (minimum needed to win)
        if (n >= 4 && isWin(game)) {
            if (player1Turn)
                cout << "Player 1 (X) wins!" << endl;
            else
                cout << "Player 2 (O) wins!" << endl;
            return 0;
        }
        
        // Switch turns
        player1Turn = !player1Turn;
    }
    
    // If loop completes without winner
    cout << "It's a tie!" << endl;
    return 0;
}

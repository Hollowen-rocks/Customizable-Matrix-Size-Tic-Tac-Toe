# Customizable Matrix Size Tic-Tac-Toe

This is a customizable matrix size Tic-Tac-Toe game implemented in C++. The game allows players to specify the number of rows and columns for the board, making it adaptable to various board sizes.

## Features

- Customizable board size (rows x columns).
- Input validation for rows, columns, and moves.
- Checks for win conditions (rows, columns, and diagonals).
- Detects draw conditions.

## How to Play

1. **Enter the number of rows and columns** for the Tic-Tac-Toe board.
2. **Players take turns** to enter their move by specifying the row and column.
3. The game checks for a win or draw after each move.
4. The game ends when a player wins or the board is full (draw).

## Code Explanation

### TicTacToe Class

The `TicTacToe` class manages the game board, player turns, and win/draw conditions.

- **Constructor**: Initializes the board and sets the current player to 'X'.
- **printBoard()**: Prints the current state of the board.
- **checkLine()**: Checks if all elements in a line (row or column) are the same as the current player.
- **checkDiagonals()**: Checks both diagonals for a win condition.
- **checkWinner()**: Checks the row, column, and diagonals of the last move to see if the current player has won.
- **isDraw()**: Checks if the board is full, indicating a draw.
- **playGame()**: Main game loop that handles player input and game state updates.

### Main Function

The `main` function prompts the user for the board size, initializes the game, and starts the game loop.

## Example Gameplay

```plaintext
Enter the number of rows: 3
Enter the number of columns: 3

 |   |  
---------
 |   |  
---------
 |   |  

Player X, enter the row and column (0-2) for your move: 0 0

X |   |  
---------
 |   |  
---------
 |   |  

Player O, enter the row and column (0-2) for your move: 1 1

X |   |  
---------
 | O |  
---------
 |   |  

...

Player X wins!

```

## Acknowledgements

Inspired by classic Tic-Tac-Toe games and developed for educational purposes.


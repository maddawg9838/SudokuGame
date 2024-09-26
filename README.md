# Sudoku Game

## Overview
This is a simple command-line implementation of a Sudoku game in C++. Players can fill in a 9x9 Sudoku board and validate their solutions. The program allows for multiple rounds of play.

## Features
- **Generate Board**: Creates a blank 9x9 Sudoku board.
- **Interactive Gameplay**: Players can input values into specific coordinates
- **Solution Validation**: Checks if the completed Sudoku board is correct
- **Replay Option**: Players can choose to play multiple rounds.

## How to Play
1. **Start the Game**: Run the program to generate a blank Sudoku board.
2. **Input Values**: Specify the row and column (1-9) where you want to place a value, followed by the value itself.
3. **Validate Solution**: The program will check if the board is correctly filled.
4. **Play Again**: After completing a game, you can choose to play again

## Prerequisites
- A C++ compiler (like g++) to run the code.

## How to Run
1. Clone the repository:
```bash
git clone https://github.com/yourusername/SudokuGame.git
cd SudokuGame
```
2. Compile the code:
```bash
g++ -o SudokuGame SudokuGame.cpp
```
3. Run the game:
```bash
./SudokuGame
```

## Code Overview
The program consists of functions to generate the board, play the game, validate the solution, and offer replay functionality.

## Key Functions
- GenerateBoard(): Initializes and displays the Sudoku board.
- PlayBoard(): Handles user input for placing values on the board.
- ValidateSolution(): Checks if the filled Sudoku board adheres to the rules.
- PlayAgain(): Prompts the user to continue or exit the game.

## Author
Madison Humphries

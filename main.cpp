#include <iostream>
#include <vector>

using namespace std;

// Function Prototypes
void GenerateBoard();
void PlayBoard();
void ValidateSolution();
bool PlayAgain();

// Global Variables
const int SIZE = 9; // Changed to a single constant for better clarity
vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); // Initialize a 9x9 board with zeros

int main()
{
    do
    {
        GenerateBoard();
        PlayBoard();
        ValidateSolution();
    } while (PlayAgain());
}

void GenerateBoard()
{
    cout << "Current Board:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void PlayBoard()
{
    int value;
    bool full = false;

    do
    {
        int cell;
        cout << "Enter the cell number (1-81) to add a value (or 0 to finish): ";
        cin >> cell;

        if (cell == 0) break; // Allow player to finish inputting

        // Convert cell number (1-81) to row and column
        int row = (cell - 1) / SIZE; // Row index
        int col = (cell - 1) % SIZE; // Column index

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != 0)
        {
            cout << "Invalid move. Please select an empty cell between 1-81." << endl;
            continue; // Prompt for input again
        }

        cout << "What value do you want to put in cell " << cell << "? ";
        cin >> value;

        board[row][col] = value; // Place the value in the selected cell

        // Check if the board is full
        full = true; // Assume the board is full
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == 0) // If any cell is still zero
                {
                    full = false; // The board is not full
                    break;
                }
            }
            if (!full) break;
        }

    } while (!full);
}

void ValidateSolution()
{
    int correctSum = 405; // Sum of numbers 1-9 is 45, for a 9x9 grid it should be 405
    bool isValid = true;

    // Validate rows
    for (int i = 0; i < SIZE; i++)
    {
        int sum = 0;
        for (int j = 0; j < SIZE; j++)
        {
            sum += board[i][j];
        }
        if (sum != 45) // Each row must sum to 45
        {
            isValid = false;
            break;
        }
    }

    // Validate columns
    if (isValid)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int sum = 0;
            for (int i = 0; i < SIZE; i++)
            {
                sum += board[i][j];
            }
            if (sum != 45) // Each column must sum to 45
            {
                isValid = false;
                break;
            }
        }
    }

    if (isValid)
    {
        cout << "Solution is correct!" << endl;
    }
    else
    {
        cout << "Something is wrong with the solution." << endl;
    }
}

bool PlayAgain()
{
    char playMore;

    cout << "Would you like to play again? Enter y or Y for yes and n or N for no: ";
    cin >> playMore;

    return playMore == 'y' || playMore == 'Y'; // Simplified return
}



#include <iostream>

using namespace std;

// Function Prototypes
void GenerateBoard();
void PlayBoard();
void ValidateSolution();
bool PlayAgain();

// Global Variables
const int COL = 9, ROW = 9;
int board[ROW][COL];

int main()
{

    do
    {
        GenerateBoard();
        PlayBoard();
        ValidateSolution();
    } while (PlayAgain() == true);
}

void GenerateBoard()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << board[i][j];
        }
    };
}

void PlayBoard()
{
    int row, col, value, filled = 0;
    int fullyFilled = 81;
    bool invalid, full;

    do
    {
        cout << "What are the coordinates for the box you want to add a value in?" << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Col: ";
        cin >> col;

        if (row < 1 || row > 9 || col < 1 || col > 9)
        {
            cout << "That is an invalid option. Please select a value between 1-9" << endl;
            invalid = true;
            while (invalid == true)
            {
                cout << "What are the coordinates for the box you want to add a value in?" << endl;
                cout << "Row: ";
                cin >> row;
                cout << "Col: ";
                cin >> col;
            }
            cout << "What is the value you want to put in this box? ";
            cout << "Value: ";
            cin >> value;

            board[row][col] = value;

            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    cout << board[i][j];
                    if (board[i][j] > 0)
                    {
                        filled++;
                    }
                }
            }

            if (filled == fullyFilled)
            {
                full = true;
                ValidateSolution();
            }
        }
    } while (full == false);
}

void ValidateSolution()
{
    int correctSum = 405, correctCol = 45, correctRow = 45;
    int row[ROW], col[COL], sum;
    bool sol = false;

    for (int i = 0; i < ROW; i++)
    {
        row[i] += board[i, 0];
        col[i] += board[0, i];
        for (int j = 0; j < COL; j++)
        {
            sum += board[i, i];
        }
    }

    for (int c = 0; 0 < ROW; c++)
    {
        if (row[c] == correctRow && col[c] == correctCol)
        {
            cout << "Solution is correct" << endl;
            sol = true;
        }
    }

    if (sol == true && sum == correctSum)
    {
        cout << "Solution is correct" << endl;
    }
    else
    {
        cout << "Something is wrong with the solution" << endl;
    }
}

bool PlayAgain()
{
    char playMore;

    cout << "Would you like to play again? Enter y or Y for yes and n or N for no" << endl;
    cin >> playMore;

    if (playMore == 'y' || playMore == 'Y')
    {
        return true;
    }
    else if (playMore == 'n' || playMore == 'N')
    {
        cout << "Thanks for Playing!" << endl;
        return false;
    }
}



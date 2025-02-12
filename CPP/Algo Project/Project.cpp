#include <iostream>
#include <vector>
#include <conio.h>
#define COMPUTER 1
#define HUMAN 2

#define SIDE 3

#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'
using namespace std;

void showBoard(char board[][SIDE]);
void showInstructions();
void initialise(char board[][SIDE]);
void declareWinner(int whoseTurn);
bool rowCrossed(char board[][SIDE]);
bool columnCrossed(char board[][SIDE]);
bool diagonalCrossed(char board[][SIDE]);
bool gameOver(char board[][SIDE]);
int minimax(char board[][SIDE], int depth, bool isAI);
int bestMove(char board[][SIDE], int moveIndex);
void playTicTacToe(int whoseTurn);

void showBoard(char board[][SIDE])
{

    cout << "\t\t\t" << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t" << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "\t\t\t-----------\n";
    cout << "\t\t\t" << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void showInstructions()
{
    cout << "\nChoose a cell numbered from 1 to 9 in the Matrix Board shown below :- \n\n";

    cout << "\t\t\t\t\t 1 | 2 | 3 \n";
    cout << "\t\t\t\t\t-----------\n";
    cout << "\t\t\t\t\t 4 | 5 | 6 \n";
    cout << "\t\t\t\t\t-----------\n";
    cout << "\t\t\t\t\t 7 | 8 | 9 \n";

    cout << endl;
}

void initialise(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            board[i][j] = '*';
        }
    }
}

void declareWinner(int whoseTurn)
{
    if (whoseTurn == COMPUTER)
        cout << "COMPUTER has won the GAME\n";
    else
        cout << "You have won the GAME\n";
}

bool rowCrossed(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != '*')
            return true;
    }
    return false;
}

bool columnCrossed(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != '*')
            return true;
    }
    return false;
}

bool diagonalCrossed(char board[][SIDE])
{

    // checking for Diagonal from Top-left corner to Bottom right corner
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != '*')
    {
        return true;
    }

    //  checking for Diagonal from Top-Right corner to Bottom left corner
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != '*')
    {
        return true;
    }

    return false;
}

bool gameOver(char board[][SIDE])
{
    return rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board);
}

int minimax(char board[][SIDE], int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    if (gameOver(board) == true)
    {
        if (isAI == true)
            return -10;
        if (isAI == false)
            return +10;
    }
    else
    {
        if (depth < 9)
        {
            if (isAI == true)
            {
                bestScore = -1000;
                for (int i = 0; i < SIDE; i++)
                {
                    for (int j = 0; j < SIDE; j++)
                    {
                        if (board[i][j] == '*')
                        {
                            board[i][j] = COMPUTERMOVE;
                            score = minimax(board, depth + 1, false);
                            board[i][j] = '*';
                            if (score > bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 1000;
                for (int i = 0; i < SIDE; i++)
                {
                    for (int j = 0; j < SIDE; j++)
                    {
                        if (board[i][j] == '*')
                        {
                            board[i][j] = HUMANMOVE;
                            score = minimax(board, depth + 1, true);
                            board[i][j] = '*';
                            if (score < bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int bestMove(char board[][SIDE], int moveIndex)
{
    int x = -1, y = -1;
    int score = 0, bestScore = -1000;
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (board[i][j] == '*')
            {
                board[i][j] = COMPUTERMOVE;
                score = minimax(board, moveIndex + 1, false);
                board[i][j] = '*';
                if (score > bestScore)
                {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x * 3 + y;
}

void playTicTacToe(int whoseTurn)
{
    system("cls");
    char board[SIDE][SIDE];
    int moveIndex = 0, x = 0, y = 0;

    initialise(board);
    showInstructions();

    while (gameOver(board) == false && moveIndex != SIDE * SIDE)
    {
        int n;
        if (whoseTurn == COMPUTER)
        {
            n = bestMove(board, moveIndex);
            x = n / SIDE;
            y = n % SIDE;
            board[x][y] = COMPUTERMOVE;
            cout << endl;

            cout << "COMPUTER has put a " << COMPUTERMOVE << " in cell : " << n + 1 << endl
                 << endl;
            showBoard(board);
            moveIndex++;
            whoseTurn = HUMAN;
        }

        else if (whoseTurn == HUMAN)
        {
            cout << endl;
            cout << "Choose from following available positions : ";

            for (int i = 0; i < SIDE; i++)
                for (int j = 0; j < SIDE; j++)
                    if (board[i][j] == '*')
                        cout << (i * 3 + j) + 1 << "  ";

            cout << "\n\nEnter the position = ";
            cin >> n;
            n--;
            x = n / SIDE;
            y = n % SIDE;

            if (board[x][y] == '*' && n < 9 && n >= 0)
            {
                board[x][y] = HUMANMOVE;
                system("cls");
                cout << "\nPLAYER has put a " << HUMANMOVE << " in cell : " << n + 1 << endl
                     << endl;
                showBoard(board);
                moveIndex++;
                whoseTurn = COMPUTER;
            }
            else if (board[x][y] != '*' && n < 9 && n >= 0)
            {
                cout << "\nPosition is occupied, select any one place from the available places\n\n";
            }
            else if (n < 0 || n > 8)
            {
                cout << "Invalid position\n";
            }
        }
    }

    if (gameOver(board) == false && moveIndex == SIDE * SIDE)
        cout << "It's a draw\n";
    else
    {
        if (whoseTurn == COMPUTER)
            whoseTurn = HUMAN;
        else if (whoseTurn == HUMAN)
            whoseTurn = COMPUTER;

        declareWinner(whoseTurn);
    }
}

int ticTacMenu()
{
    system("cls");
    char choice;
    printf("Enter X to exit game\n");
    printf("A. Play First\n");
    printf("B. Let Computer make first move\n");
    printf("Choose from A-B: ");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice > 90)
    {
        choice = choice - 32;
    }
    if (choice == 'X')
    {
        return -1;
    }
    switch (choice)
    {
    case 'A':
        playTicTacToe(HUMAN);
        break;
    case 'B':
        playTicTacToe(COMPUTER);
        break;
    default:
        break;
    }
    return 1;
}

char crossWord[10][10];

bool isValidHorizontal(int row, int col, string word)
{

    if (10 - col < word.length())
        return false;

    for (int i = 0, j = col; i < word.length(); ++i, j++)
    {
        if (crossWord[row][j] != '-' && crossWord[row][j] != word[i])
        {
            return false;
        }
    }

    return true;
}

bool isValidVertical(int row, int col, string word)
{

    if (10 - row < word.length())
        return false;

    for (int i = row, j = 0; j < word.length(); ++i, j++)
    {
        if (crossWord[i][col] != '-' && crossWord[i][col] != word[j])
        {
            return false;
        }
    }

    return true;
}

void setHorizontal(int row, int col, string word, bool state[])
{

    for (int i = 0, j = col; i < word.size(); ++i, j++)
    {
        if (crossWord[row][j] != '+')
        {

            if (crossWord[row][j] == word[i])
                state[i] = false;
            else
                state[i] = true;
            crossWord[row][j] = word[i];
        }
    }
}

void setVertical(int row, int col, string word, bool state[])
{

    for (int i = 0, j = row; i < word.size(); ++i, j++)
    {
        if (crossWord[j][col] != '+')
        {

            if (crossWord[j][col] == word[i])
                state[i] = false;
            else
                state[i] = true;
            crossWord[j][col] = word[i];
        }
    }
}

void resetHorizontal(int row, int col, bool state[], int size)
{

    for (int i = 0, j = col; i < size; ++i, j++)
    {
        if (state[i] == true)
            crossWord[row][j] = '-';
    }
    return;
}

void resetVertical(int row, int col, bool state[], int size)
{

    for (int i = 0, j = row; i < size; ++i, j++)
    {
        if (state[i] == true)
            crossWord[j][col] = '-';
    }
    return;
}

void set_value(bool helper[], int len)
{
    for (int i = 0; i < len; i++)
    {
        helper[i] = false;
    }
}

bool crossWordHelper(string input[], int size, int index)
{

    if (index == size)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {

                cout << crossWord[i][j];
            }
            cout << endl;
        }
        return true;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (crossWord[i][j] == '-' || crossWord[i][j] == input[index][0])
            {
                int length = input[index].size();
                bool state[length];
                set_value(state, length);

                if (isValidHorizontal(i, j, input[index]))
                {
                    setHorizontal(i, j, input[index], state);
                    if (crossWordHelper(input, size, index + 1))
                    {
                        return true;
                    }
                    resetHorizontal(i, j, state, length);
                }

                if (isValidVertical(i, j, input[index]))
                {
                    setVertical(i, j, input[index], state);
                    if (crossWordHelper(input, size, index + 1))
                    {
                        return true;
                    }
                    resetVertical(i, j, state, length);
                }
            }
        }
    }
    return false;
}

void solveCrossWord(string input[], int size)
{

    bool res = crossWordHelper(input, size, 0);
    return;
}

int crosswordmenu()
{
    system("cls");
    string ss;
    for (int i = 0; i < 10; i++)
    {
        cin >> ss;
        for (int j = 0; j < ss.size(); j++)
        {
            crossWord[i][j] = ss[j];
        }
    }

    char s[200];
    cin >> s;

    string input[10];
    char ch;
    string word = "";
    int a = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {

        if (s[i] == ';')
        {
            input[a++] = word;
            word = "";
        }
        else
        {
            word += s[i];
        }
    }
    input[a++] = word;
    system("cls");

    solveCrossWord(input, a);
    return 0;
}

const int n = 9;
void printSudoku(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
bool SDK(int **a, int &x, int &y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                x = i;
                y = j;
                return false;
            }
        }
    }
    return true;
}
bool safe(int **a, int x, int y, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (i != y)
        {
            if (a[x][i] == k)
            {
                return false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != x)
        {
            if (a[i][y] == k)
            {
                return false;
            }
        }
    }
    for (int i = x - (x % 3); i < x - (x % 3) + 3; i++)
    {
        for (int j = y - (y % 3); j < y - (y % 3) + 3; j++)
        {
            if (i != x || j != y)
            {
                if (a[i][j] == k)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
bool SUDOKU(int **a, int n)
{
    system("cls");
    int x, y;
    if (SDK(a, x, y))
    {
        return true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (safe(a, x, y, n, i))
        {
            a[x][y] = i;
            printSudoku(a, n);
            if (SUDOKU(a, n))
            {
                return true;
            }
            a[x][y] = 0;
        }
    }
    return false;
}
int sudokumain()
{
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    if (SUDOKU(a, n))
    {
        printSudoku(a, n);
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}

int mainMenu()
{
    system("cls");
    char choice;
    printf("Enter X to exit game\n");
    printf("A. Play Tic Tac Toe\n");
    printf("B. Solve a Sudoku\n");
    printf("C. Solve Crossword\n");
    printf("Choose from A-C: ");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice > 90)
    {
        choice = choice - 32;
    }
    if (choice == 'X')
    {
        return -1;
    }
    switch (choice)
    {
    case 'A':
        ticTacMenu();
        break;
    case 'B':
        sudokumain();
        break;
    case 'C':
        crosswordmenu();
        break;
    default:
        break;
    }
    return 1;
}

int main()
{
    while (1)
    {
        int returnValue = mainMenu();
        if (returnValue == -1)
        {
            break;
        }
        printf("\n\nPress any key to continue...\n");
        getch();
    }
    return 0;
}
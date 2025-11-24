#include <iostream>



using namespace std;

// Changed from 9 to 8 for an 8x8 Sudoku

#define N 8

void print(int arr[N][N])

{

    for (int i = 0; i < N; i++)

    {

        for (int j = 0; j < N; j++)

            cout << arr[i][j] << " ";

        cout << endl;

    }

}
bool isSafe(int grid[N][N], int row, int col, int num)

{

    for (int x = 0; x < N; x++)

        if (grid[row][x] == num)

            return false;

    for (int x = 0; x < N; x++)

        if (grid[x][col] == num)

            return false;

    int startRow = row - row % 4,

        startCol = col - col % 2;

   

    for (int i = 0; i < 4; i++)

        for (int j = 0; j < 2; j++)

            if (grid[i + startRow][j + startCol] == num)

                return false;



    return true;

}
bool solveSudoku(int grid[N][N], int row, int col)

{
    if (row == N - 1 && col == N)

        return true;

    if (col == N) {

        row++;

        col = 0;

    }
    if (grid[row][col] > 0)

        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++)

    {

        if (isSafe(grid, row, col, num))

        {

            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))

                return true;

        }

        grid[row][col] = 0;

    }

    return false;

}

int main()

{

    int grid[N][N] = {

        {1, 0, 3, 4, 5, 6, 0, 8},

        {5, 6, 7, 8, 1, 0, 3, 4},

        {3, 4, 0, 2, 7, 8, 5, 0},

        {0, 8, 5, 6, 3, 4, 1, 2},

        {2, 1, 4, 0, 6, 5, 8, 7},

        {6, 0, 8, 7, 2, 1, 4, 3},

        {4, 3, 2, 1, 8, 0, 6, 5},

        {8, 7, 0, 5, 0, 3, 2, 1}

    };



    if (solveSudoku(grid, 0, 0))

        print(grid);

    else

        cout << "no solution exists" << endl;



    return 0;

}

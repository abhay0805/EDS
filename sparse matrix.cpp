#include <iostream>
using namespace std;

// Structure to represent a sparse matrix entry in triplet form
class SparseMatrix {
public:
    int row, col, val;

    // Transpose a sparse matrix
    void simpleTranspose(SparseMatrix mat[10], int size) {
        for (int i = 0; i <= size; i++) {
            int temp = mat[i].row;
            mat[i].row = mat[i].col;
            mat[i].col = temp;
        }

        cout << "Transposed Matrix (Simple Method):\n";
        displayMatrix(mat, size);
    }

    // Fast Transpose a sparse matrix
    void fastTranspose(SparseMatrix source[], SparseMatrix result[]) {
        int numCols = source[0].col;
        int numVals = source[0].val;

        result[0].row = source[0].col;
        result[0].col = source[0].row;
        result[0].val = source[0].val;

        int count[100] = {0};     // count of each column
        int index[100];           // position of each element in result

        // Count how many elements are in each column of the original matrix
        for (int i = 1; i <= numVals; i++) {
            count[source[i].col]++;
        }

        index[0] = 1;  // result starts from index 1
        for (int i = 1; i < numCols; i++) {
            index[i] = index[i - 1] + count[i - 1];
        }

        // Build the result matrix
        for (int i = 1; i <= numVals; i++) {
            int col = source[i].col;
            int pos = index[col];

            result[pos].row = source[i].col;
            result[pos].col = source[i].row;
            result[pos].val = source[i].val;

            index[col]++;
        }

        cout << "Fast Transposed Matrix:\n";
        displayMatrix(result, result[0].val);
    }

    // Add two sparse matrices
    void addMatrices(SparseMatrix A[], SparseMatrix B[]) {
        if (A[0].row != B[0].row || A[0].col != B[0].col) {
            cout << "Matrices dimensions do not match for addition.\n";
            return;
        }

        SparseMatrix result[200];
        result[0].row = A[0].row;
        result[0].col = A[0].col;

        int i = 1, j = 1, k = 1;
        while (i <= A[0].val && j <= B[0].val) {
            if (A[i].row == B[j].row && A[i].col == B[j].col) {
                result[k] = {A[i].row, A[i].col, A[i].val + B[j].val};
                i++; j++;
            } else if ((A[i].row < B[j].row) || (A[i].row == B[j].row && A[i].col < B[j].col)) {
                result[k] = A[i++];
            } else {
                result[k] = B[j++];
            }
            k++;
        }

        while (i <= A[0].val) result[k++] = A[i++];
        while (j <= B[0].val) result[k++] = B[j++];

        result[0].val = k - 1;
        cout << "Resultant Matrix after Addition:\n";
        displayMatrix(result, result[0].val);
    }

    // Multiply two sparse matrices
    void multiplyMatrices(SparseMatrix A[], SparseMatrix B[]) {
        if (A[0].col != B[0].row) {
            cout << "Cannot multiply: Column of A != Row of B.\n";
            return;
        }

        SparseMatrix result[200];
        result[0].row = A[0].row;
        result[0].col = B[0].col;
        result[0].val = 0;
        int index = 1;

        for (int i = 0; i < A[0].row; i++) {
            for (int j = 0; j < B[0].col; j++) {
                int sum = 0;
                for (int x = 1; x <= A[0].val; x++) {
                    if (A[x].row != i) continue;
                    for (int y = 1; y <= B[0].val; y++) {
                        if (B[y].row != j) continue;
                        if (A[x].col == B[y].col)
                            sum += A[x].val * B[y].val;
                    }
                }

                if (sum != 0) {
                    result[index++] = {i, j, sum};
                }
            }
        }

        result[0].val = index - 1;
        cout << "Resultant Matrix after Multiplication:\n";
        displayMatrix(result, result[0].val);
    }

    // Display matrix in triplet form
    void displayMatrix(SparseMatrix mat[], int size) {
        for (int i = 0; i <= size; i++) {
            cout << mat[i].row << " " << mat[i].col << " " << mat[i].val << endl;
        }
    }
};

// Input matrix and convert to triplet form
void inputMatrix(SparseMatrix mat[]) {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[rows][cols];
    cout << "Enter the matrix values:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    int k = 1;
    mat[0] = {rows, cols, 0}; // initialize header
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
                mat[k++] = {i, j, matrix[i][j]};

    mat[0].val = k - 1;

    cout << "Triplet Representation:\n";
    for (int i = 0; i < k; i++)
        cout << mat[i].row << " " << mat[i].col << " " << mat[i].val << endl;
}

// Main function
int main() {
    SparseMatrix matrixOps;
    SparseMatrix A[100], B[100], T[100];
    int choice;

    cout << "\nChoose Operation:\n";
    cout << "1. Simple Transpose\n";
    cout << "2. Fast Transpose\n";
    cout << "3. Addition\n";
    cout << "4. Multiplication\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            inputMatrix(A);
            matrixOps.simpleTranspose(A, A[0].val);
            break;

        case 2:
            inputMatrix(A);
            matrixOps.fastTranspose(A, T);
            break;

        case 3:
            cout << "Matrix A:\n";
            inputMatrix(A);
            cout << "Matrix B:\n";
            inputMatrix(B);
            matrixOps.addMatrices(A, B);
            break;

        case 4:
            cout << "Matrix A:\n";
            inputMatrix(A);
            cout << "Matrix B:\n";
            inputMatrix(B);
            matrixOps.fastTranspose(B, T); // Transpose B for easier multiplication
            matrixOps.multiplyMatrices(A, T);
            break;

        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}


// EECS 348 - Lab 5
// C++ Programming - Matrix Operations
// Name: Peter Lauman

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

using Matrix = vector<vector<int>>;

// Prints a matrix with aligned columns.
void printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << setw(6) << value;
        }
        cout << '\n';
    }
}

// Problem 1: Loads N and two N x N matrices from a file.
bool loadMatrices(const string& filename, Matrix& A, Matrix& B) {
    ifstream input(filename);

    if (!input) {
        cerr << "Error: could not open " << filename << ".\n";
        return false;
    }

    int N;
    if (!(input >> N) || N <= 0) {
        cerr << "Error: matrix size must be a positive integer.\n";
        return false;
    }

    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(input >> A[i][j])) {
                cerr << "Error: not enough values for Matrix A.\n";
                return false;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(input >> B[i][j])) {
                cerr << "Error: not enough values for Matrix B.\n";
                return false;
            }
        }
    }

    return true;
}

// Problem 2: Adds two matrices.
Matrix addMatrices(const Matrix& A, const Matrix& B) {
    int N = static_cast<int>(A.size());
    Matrix result(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Problem 3: Multiplies two matrices.
Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int N = static_cast<int>(A.size());
    Matrix result(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Problem 4: Displays the main and secondary diagonal sums.
void displayDiagonalSums(const Matrix& matrix) {
    int N = static_cast<int>(matrix.size());
    int mainSum = 0;
    int secondarySum = 0;

    for (int i = 0; i < N; ++i) {
        mainSum += matrix[i][i];
        secondarySum += matrix[i][N - 1 - i];
    }

    cout << "Main diagonal sum: " << mainSum << '\n';
    cout << "Secondary diagonal sum: " << secondarySum << '\n';
}

// Problem 5: Swaps two rows if both indices are valid.
bool swapRows(Matrix& matrix, int row1, int row2) {
    int N = static_cast<int>(matrix.size());

    if (row1 < 0 || row1 >= N || row2 < 0 || row2 >= N) {
        cout << "Invalid row index.\n";
        return false;
    }

    swap(matrix[row1], matrix[row2]);
    return true;
}

// Problem 6: Swaps two columns if both indices are valid.
bool swapColumns(Matrix& matrix, int col1, int col2) {
    int N = static_cast<int>(matrix.size());

    if (col1 < 0 || col1 >= N || col2 < 0 || col2 >= N) {
        cout << "Invalid column index.\n";
        return false;
    }

    for (int i = 0; i < N; ++i) {
        swap(matrix[i][col1], matrix[i][col2]);
    }

    return true;
}

// Problem 7: Updates one matrix element if the indices are valid.
bool updateElement(Matrix& matrix, int row, int col, int newValue) {
    int N = static_cast<int>(matrix.size());

    if (row < 0 || row >= N || col < 0 || col >= N) {
        cout << "Invalid row or column index.\n";
        return false;
    }

    matrix[row][col] = newValue;
    return true;
}

int main() {
    string filename;
    Matrix A, B;

    cout << "Enter input file name: ";
    cin >> filename;

    if (!loadMatrices(filename, A, B)) {
        return 1;
    }

    cout << "\nMatrix A:\n";
    printMatrix(A);

    cout << "\nMatrix B:\n";
    printMatrix(B);

    cout << "\nA + B:\n";
    printMatrix(addMatrices(A, B));

    cout << "\nA * B:\n";
    printMatrix(multiplyMatrices(A, B));

    cout << "\nDiagonal sums of Matrix A:\n";
    displayDiagonalSums(A);

    // Each editing problem starts with a fresh copy of Matrix A.
    Matrix rowMatrix = A;
    int row1, row2;
    cout << "\nEnter two row indices to swap: ";
    cin >> row1 >> row2;
    if (swapRows(rowMatrix, row1, row2)) {
        cout << "Matrix after swapping rows " << row1 << " and " << row2 << ":\n";
        printMatrix(rowMatrix);
    }

    Matrix columnMatrix = A;
    int col1, col2;
    cout << "\nEnter two column indices to swap: ";
    cin >> col1 >> col2;
    if (swapColumns(columnMatrix, col1, col2)) {
        cout << "Matrix after swapping columns " << col1 << " and " << col2 << ":\n";
        printMatrix(columnMatrix);
    }

    Matrix updateMatrix = A;
    int row, col, newValue;
    cout << "\nEnter row, column, and new value: ";
    cin >> row >> col >> newValue;
    if (updateElement(updateMatrix, row, col, newValue)) {
        cout << "Matrix after updating (" << row << ", " << col << ") to "
             << newValue << ":\n";
        printMatrix(updateMatrix);
    }

    return 0;
}

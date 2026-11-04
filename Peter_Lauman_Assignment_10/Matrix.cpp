#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <utility>
using namespace std;

class Matrix {
private:
    int n;
    int** data;
public:
    explicit Matrix(int size = 0) : n(size), data(nullptr) {
        if (n > 0) {
            data = new int*[n];
            for (int i = 0; i < n; ++i) {
                data[i] = new int[n]{};
            }
        }
    }
    Matrix(const Matrix& other) : Matrix(other.n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] = other.data[i][j];
    }
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            Matrix temp(other);
            swap(n, temp.n);
            swap(data, temp.data);
        }
        return *this;
    }
    ~Matrix() {
        for (int i = 0; i < n; ++i) delete[] data[i];
        delete[] data;
    }
    int size() const { return n; }
    void read(istream& in) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (!(in >> data[i][j])) throw runtime_error("Invalid matrix data");
    }
    void print() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << setw(4) << data[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
    Matrix operator+(const Matrix& other) const {
        if (n != other.n) throw invalid_argument("Matrix sizes differ");
        Matrix result(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }
    Matrix operator*(const Matrix& other) const {
        if (n != other.n) throw invalid_argument("Matrix sizes differ");
        Matrix result(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }
    int mainDiagonalSum() const {
        int total = 0;
        for (int i = 0; i < n; ++i) total += data[i][i];
        return total;
    }
    int secondaryDiagonalSum() const {
        int total = 0;
        for (int i = 0; i < n; ++i) total += data[i][n - 1 - i];
        return total;
    }
    void swapRows(int a, int b) {
        if (a < 0 || b < 0 || a >= n || b >= n) throw out_of_range("Invalid row index");
        swap(data[a], data[b]);
    }
    void swapColumns(int a, int b) {
        if (a < 0 || b < 0 || a >= n || b >= n) throw out_of_range("Invalid column index");
        for (int i = 0; i < n; ++i) swap(data[i][a], data[i][b]);
    }
    void update(int row, int col, int value) {
        if (row < 0 || col < 0 || row >= n || col >= n) throw out_of_range("Invalid element index");
        data[row][col] = value;
    }
};

// Matrix is intentionally passed by value so the original remains unchanged.
Matrix swappedRows(Matrix matrix, int first = 0, int second = 1) {
    matrix.swapRows(first, second);
    return matrix;
}
Matrix swappedColumns(Matrix matrix, int first = 0, int second = 1) {
    matrix.swapColumns(first, second);
    return matrix;
}
Matrix updatedMatrix(Matrix matrix, int row = 0, int col = 0, int value = 100) {
    matrix.update(row, col, value);
    return matrix;
}

int main() {
    cout << "Enter input filename: ";
    string filename;
    getline(cin, filename);
    cout << "\n";
    ifstream input(filename);
    if (!input) {
        cerr << "Cannot open file: " << filename << '\n';
        return 1;
    }
    int n;
    if (!(input >> n) || n <= 0) {
        cerr << "Invalid matrix size\n";
        return 1;
    }
    try {
        Matrix A(n), B(n);
        A.read(input);
        B.read(input);
        cout << "Matrix A:\n"; A.print();
        cout << "Matrix B:\n"; B.print();
        cout << "A + B:\n"; (A + B).print();
        cout << "A * B:\n"; (A * B).print();
        cout << "Diagonal sums for Matrix A:\n";
        cout << "Main diagonal sum: " << A.mainDiagonalSum() << '\n';
        cout << "Secondary diagonal sum: " << A.secondaryDiagonalSum() << "\n\n";
        int row1 = 0, row2 = n > 2 ? 2 : (n > 1 ? 1 : 0);
        cout << "Problem 5 - Rows " << row1 << " and " << row2 << " swapped:\n";
        swappedRows(A, row1, row2).print();
        int col1 = 0, col2 = n > 2 ? 2 : (n > 1 ? 1 : 0);
        cout << "Problem 6 - Columns " << col1 << " and " << col2 << " swapped:\n";
        swappedColumns(A, col1, col2).print();
        cout << "Problem 7 - Updated matrix:\n";
        updatedMatrix(A, n > 1 ? 1 : 0, n > 2 ? 2 : 0, 99).print();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

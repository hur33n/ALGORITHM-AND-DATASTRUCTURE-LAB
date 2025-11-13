#include <iostream>
using namespace std;

void booleanMatrix(int mat[][4], int rows, int cols) {
    // Step 1: Mark rows and columns containing 1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 1) {
                // Replace all zeros in j-th column by -1
                for (int idx = 0; idx < rows; idx++) {
                    if (mat[idx][j] == 0)
                        mat[idx][j] = -1;
                }
                // Replace all zeros in i-th row by -1
                for (int idx = 0; idx < cols; idx++) {
                    if (mat[i][idx] == 0)
                        mat[i][idx] = -1;
                }
            }
        }
    }

    // Step 2: Replace all -1 by 1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == -1)
                mat[i][j] = 1;
        }
    }
}

int main() {
    int mat[3][4] = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    int rows = 3, cols = 4;
    booleanMatrix(mat, rows, cols);

    // Print modified matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

bool binarySearch(int mat[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (mat[mid] == target)
            return true;  
        else if (target > mat[mid])
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return false;
}

bool matSearch(int mat[][3], int rows, int cols, int x) {
    for (int i = 0; i < rows; i++) {
        if (binarySearch(mat[i], cols, x))
            return true; 
    }
    return false; 
}

int main() {
    int mat[3][3] = {
        {3, 30, 38},
        {20, 52, 54},
        {35, 60, 69}
    };
    int x = 35;

    if (matSearch(mat, 3, 3, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}
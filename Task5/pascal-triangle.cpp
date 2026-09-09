#include <vector>
using namespace std;
/**
 * Generates Pascal's Triangle up to n rows
 * Time Complexity: O(n²) - triangular number of elements
 * Space Complexity: O(n²) to store all rows
 */
vector<vector<long long>> generatePascalTriangle(int n) {
    vector<vector<long long>> triangle;
    // Handle n <= 0 case
    if (n <= 0) {
        return triangle; // no rows requested
    }

    for (int i = 0; i < n; i++) {
        vector<long long> Row(i + 1);
        Row[0] = 1;              // first entry of every row is 1
        Row[i] = 1;            // last entry of every row is 1

        // Each inner value is the sum of the two values above it in the previous row ... Pascal's rule
        for (int j = 1; j < i; j++) {
            Row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(Row);
    }

    return triangle;
}




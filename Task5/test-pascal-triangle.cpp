#include <iostream>
#include <vector>
#include "pascal-triangle.cpp"
using namespace std;

void printTriangle(const vector<vector<long long>>& triangle) {
    for (const auto& row : triangle) {
        for (size_t i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i + 1 < row.size()) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test Case 1: n = 0 ... no rows at all
    {
        auto triangle = generatePascalTriangle(0);
        cout << "Test 1 (n = 0): " << (triangle.empty() ? "PASS" : "FAIL")
             << " (rows = " << triangle.size() << ")" << endl;
    }

    // Test Case 2: n = 1 -> single row {1}
    {
        auto triangle = generatePascalTriangle(1);
        bool pass = (triangle.size() == 1 && triangle[0] == vector<long long>{1});
        cout << "Test 2 (n = 1): " << (pass ? "PASS" : "FAIL") << endl;
        printTriangle(triangle);
    }

    // Test Case 3: n = 5 -> verify row 5 (index 4) == {1, 4, 6, 4, 1}
    {
        auto triangle = generatePascalTriangle(5);
        vector<long long> expectedRow5 = {1, 4, 6, 4, 1};
        bool pass = (triangle.size() == 5 && triangle[4] == expectedRow5);
        cout << "Test 3 (n = 5, check row 5): " << (pass ? "PASS" : "FAIL") << endl;
        cout << "Full triangle:" << endl;
        printTriangle(triangle);
    }

    return 0;
}

#include <iostream>
#include <vector>
#include "mode.cpp"
using namespace std;

void printResult(const vector<int>& modes, const string& testName) {
    cout << testName << ": ";
    if (modes.empty()) {
        cout << "No mode (empty array)";
    } else if (modes.size() == 1) {
        cout << "Mode = " << modes[0];
    } else {
        cout << "Multiple modes = {";
        for (int i = 0; i < modes.size(); ++i) {
            cout << modes[i];
            if (i < modes.size() - 1) cout << ", ";
        }
        cout << "}";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Array with unique mode
    vector<int> arr1 = {1, 2, 3, 2, 4, 2, 5};
    vector<int> result1 = findMode(arr1);
    printResult(result1, "Unique mode (2 appears 3 times)");
    // Expected: Mode = 2
    
    // Test Case 2: Array with multiple modes
    vector<int> arr2 = {1, 2, 3, 1, 3, 4, 5};
    vector<int> result2 = findMode(arr2);
    printResult(result2, "Multiple modes (1 and 3 appear twice)");
    // Expected: Multiple modes = {1, 3}
    
    // Test Case 3: Empty array
    vector<int> arr3 = {};
    vector<int> result3 = findMode(arr3);
    printResult(result3, "Empty array");
    // Expected: No mode (empty array)
    
    return 0;
}
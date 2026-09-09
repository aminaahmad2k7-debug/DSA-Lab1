#include <iostream>
#include <vector>
#include <iomanip>  // ADDED: for std::setw if needed
#include "find-indices.cpp"
using namespace std;

// Helper to print a vector of indices
void printIndices(const vector<int>& indices) {
    if (indices.empty()) {
        cout << "[] (no occurrences)\n";
        return;
    }
    cout << "[";
    for (size_t i = 0; i < indices.size(); ++i) {
        cout << indices[i];
        if (i + 1 < indices.size()) cout << ", ";
    }
    cout << "]\n";
}

// ADDED: Function to run a single test with expected output
void runTest(const vector<int>& arr, int key, const vector<int>& expected, const string& testName) {
    vector<int> result = findAllIndices(arr, key);
    cout << testName << ": ";
    if (result == expected) {
        cout << "PASS - ";
    } else {
        cout << "FAIL - ";
    }
    cout << "Got: ";
    printIndices(result);
    cout << "     Expected: ";
    printIndices(expected);
}

int main() {
    cout << "=== Task 3: Find All Indices Tests ===\n\n";
    
    // Test case 1: Multiple occurrences
    vector<int> arr1 = {1, 2, 3, 2, 4, 2, 5};
    vector<int> expected1 = {1, 3, 5};
    runTest(arr1, 2, expected1, "Test 1 - Multiple occurrences");
    
    // Test case 2: Key not present
    vector<int> arr2 = {10, 20, 30, 40};
    vector<int> expected2 = {};
    runTest(arr2, 99, expected2, "Test 2 - Key not present");
    
    // Test case 3: Empty array
    vector<int> arr3;
    vector<int> expected3 = {};
    runTest(arr3, 5, expected3, "Test 3 - Empty array");
    
    // ADDED: Test case 4: Key at first position
    vector<int> arr4 = {5, 1, 2, 3, 4};
    vector<int> expected4 = {0};
    runTest(arr4, 5, expected4, "Test 4 - Key at first position");
    
    // ADDED: Test case 5: Key at last position
    vector<int> arr5 = {1, 2, 3, 4, 5};
    vector<int> expected5 = {4};
    runTest(arr5, 5, expected5, "Test 5 - Key at last position");
    
    // ADDED: Test case 6: All elements same
    vector<int> arr6 = {7, 7, 7, 7, 7};
    vector<int> expected6 = {0, 1, 2, 3, 4};
    runTest(arr6, 7, expected6, "Test 6 - All elements same");
    
    cout << "\nAll tests completed.\n";
    return 0;
}
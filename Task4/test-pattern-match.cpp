#include <iostream>
#include <string>
#include "pattern-match.cpp"
using namespace std;


void testPatternMatch(const string& text, const string& pattern, const string& testName) {
    int result = naiveSearch(text, pattern);
    cout << testName << ": ";
    cout << "Pattern \"" << pattern << "\" found at index " << result << endl;
}

int main() {
    // Test Case 1: Pattern at the beginning of the text
    testPatternMatch("hello world", "hello", "Test 1 (pattern at beginning)");

    // Test Case 2: Pattern at the end of the text
    testPatternMatch("hello world", "world", "Test 2 (pattern at end)");

    // Test Case 3: Pattern not present in the text
    testPatternMatch("hello world", "xyz", "Test 3 (pattern not present)");

    // Test Case 4: Empty pattern (matches at index 0 by convention)
    testPatternMatch("hello world", "", "Test 4 (empty pattern)");

    return 0;
}

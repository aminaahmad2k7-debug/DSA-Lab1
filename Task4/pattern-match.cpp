#include <string>
using namespace std;

 /*Time Complexity: O(n*m) where n=text length, m=pattern length
 * Space Complexity: O(1) - constant extra space */

int naiveSearch(const string& text, const string& pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    // Handle empty pattern case
    if (m == 0) {
        return 0; // Empty pattern matches at position 0
    }
    
    // If pattern longer than text, no match possible
    if (m > n) {
        return -1;
    }
    // Slide the pattern over the text one position at a time
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        // Compare the pattern with the text starting at position i
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
    // If full pattern matched
        if (j == m) {
            return i;
        }
    }

    return -1; // pattern was not found anywhere in the text
}

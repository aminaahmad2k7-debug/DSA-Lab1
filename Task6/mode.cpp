#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(n) - for frequency map
 */

vector<int> findMode(const vector<int>& arr) {
    vector<int> modes;

    if (arr.empty()) { // handle empty array case
        return modes; 
    }

    // Build a frequency histogram: value ... number of occurrences
    unordered_map<int, int> frequency;
    for (int value : arr) {
        frequency[value]++;
    }

    // Find the highest frequency in the histogram
    int maxFrequency = 0;
    for (const auto& entry : frequency) {
        maxFrequency = max(maxFrequency, entry.second);
    }

    // Collect every value that reaches the highest frequency
    for (const auto& entry : frequency) {
        if (entry.second == maxFrequency) {
            modes.push_back(entry.first);
        }
    }

    // Sort modes for consistent output
    sort(modes.begin(), modes.end());
    return modes;
}

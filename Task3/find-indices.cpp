#include <vector>
using namespace std;

/**
 * Finds all indices of a given key in an array
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(k) where k is number of occurrences
 */
vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;
    
    // FIXED: Use size_t to avoid signed/unsigned mismatch
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            // Cast size_t to int for return type consistency
            indices.push_back(static_cast<int>(i));
        }
    }
    
    return indices;
}
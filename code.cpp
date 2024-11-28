#include <bits/stdc++.h>
using namespace std;

vector<int> sortBinaryNumbers(const vector<vector<int>>& v) {
    vector<pair<long long, int>> vp;

    // Loop through each row in the input 2D array
    for (int j = 0; j < v.size(); j++) {
        long long x = 0;  // Use long long to store the binary number

        // Convert the indices to a binary number by setting the corresponding bits
        for (auto it : v[j]) {
            x += (1LL << it);  // Set the bit at position 'it'
        }

        vp.push_back({x, j});  // Store the binary value and the original index
    }

    // Sort the vector in descending order based on the binary value
    sort(vp.begin(), vp.end(), greater<pair<long long, int>>());

    // Extract the indices from the sorted pairs
    vector<int> ans;
    for (auto it : vp) {
        ans.push_back(it.second);  // Push the original index into the result
    }

    return ans;
}

int main() {
    vector<vector<int>> bitArrays = {{0, 2}, {2, 3}, {2, 1}};
    
    vector<int> result = sortBinaryNumbers(bitArrays);
    
    // Output the sorted indices
    for (int idx : result) {
        cout << idx << " ";
    }
    
    return 0;
}

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > v(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        return tabulatedSolve(text1, text2, v);
    }

    int tabulatedSolve(string& text1, string& text2, vector<vector<int> >& v)
    {
        // base case
        int rows = static_cast<int>(v.size());
        int cols = static_cast<int>(v[0].size());
        for (int k = 0; k < cols - 1; ++k) v[0][k] = 0;
        for (int l = 0; l < rows - 1; ++l) v[l][0] = 0;

        // recursion to for loop
        for (int q = 1; q <= rows - 1; ++q)
        {
            for (int x = 1; x <= cols - 1; ++x)
            {
                // recurrence
                if (text1[q - 1] == text2[x - 1])
                {
                    v[q][x] = 1 + v[q - 1][x - 1];
                }
                else
                {
                    int left = v[q - 1][x];
                    int right = v[q][x - 1];
                    v[q][x] = max(left, right);
                }
            }
        }
        return v[rows - 1][cols - 1];
    }
};

int main() {
    Solution s;
    auto answer = s.longestCommonSubsequence("abc", "def");
    cout << answer << endl;

    return 0;
}
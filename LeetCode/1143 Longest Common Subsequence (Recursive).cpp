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
        vector<vector<int> > v(text1.length(), vector<int>(text2.length(), -1));
        return solve(text1.length() - 1, text2.length() - 1, text1, text2, v);
    }

    int solve(int i, int j, string& text1, string& text2, vector<vector<int> > &v)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (v[i][j] != -1)
            return v[i][j];

        if (text1[i] == text2[j])
        {
            v[i][j] = 1 + solve(i - 1, j - 1, text1, text2, v);
            return v[i][j];
        }

        int left = solve(i - 1, j, text1, text2, v);
        int right = solve(i, j - 1, text1, text2, v);
        v[i][j] = max(left, right);
        return v[i][j];
    }
};

int main() {
    Solution s;
    auto answer = s.longestCommonSubsequence("abcde", "ace");
    cout << answer << endl;

    return 0;
}

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int> > v(s.length() + 1, vector<int>(t.length() + 1, 0));
        return tabulatedSolve(s, t, v);
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

    void print(vector<vector<int> > &v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    auto answer = s.longestPalindromeSubseq("cbbd");
    cout << answer << endl;

    return 0;
}
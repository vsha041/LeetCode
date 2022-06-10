#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
        vector<vector<int> > v(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        int lcs = tabulatedSolve(word1, word2, v);
	    return word1.length() - lcs + word2.length() - lcs;
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
    auto answer = s.minDistance("leetcode", "etco");
    cout << answer << endl;

    return 0;
}
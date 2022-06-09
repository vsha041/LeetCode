#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int> > v(n, vector<int>(5, 0));
        for (int i = 0; i < 5; ++i)
        {
            v[0][i] = 1;
        }

        for (auto i = 1; i < n; i++)
        {
            auto prevSum = accumulate(v[i - 1].begin(), v[i - 1].end(), 0);
            for (auto j = 0; j < 5; j++)
            {
                if (j == 0)
                {
                    v[i][j] = prevSum;
                }
                else
                {
                    v[i][j] = v[i][j - 1] - v[i - 1][j - 1];
                }
            }
        }

        auto answer = accumulate(v[n - 1].begin(), v[n - 1].end(), 0);
        return answer;
    }
};

int main() {
    Solution s;
    for (int i = 1; i < 51; ++i)
    {
        auto answer = s.countVowelStrings(i);
        cout << i << "," << answer << endl;
    }

    return 0;
}
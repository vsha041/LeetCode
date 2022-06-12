#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> trees(n + 1, 0);
        trees[1] = 1;
        trees[2] = 2;

        for(int i = 3; i <= n; i++){
            for (int j = 1; j <= i; j++)
            {
                int left = (1 - j) < 0 ? j - 1 : 1 - j;
                int right = i - j;

                int subTreeSum = 0;
                if (left == 0 || right == 0)
                    subTreeSum = trees[left] + trees[right];
                else
                    subTreeSum = trees[left] * trees[right];

                trees[i] = trees[i] + subTreeSum;
            }
        }

        return trees[n];
    }
};

int main() {
    Solution s;    
    vector<int> cases { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    for (size_t i = 0; i < cases.size(); i++)
    {
        int result = s.numTrees(cases[i]);
        cout << cases[i] << " " << result << endl;
    }

    return 0;
}

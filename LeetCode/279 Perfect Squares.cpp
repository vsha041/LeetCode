#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <sstream>
#include <random>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> output(n + 1, INT_MAX);
        output[0] = 0;
        output[1] = 1;
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> squares;
        int i = 1;
        while (true)
        {
            int square = i * i;
            if (square > n)
                break;

            squares.emplace_back(square);
            output[square] = 1;
            ++i;
        }

        for (int i = 2; i < n + 1; ++i)
        {
            for (int j = 0; j < squares.size(); ++j)
            {
                if (i < squares[j]) break;

                int perfectSquare = squares[j];
                int maxTake = i / perfectSquare;
                int leftToTake = i % perfectSquare;
                output[i] = min(output[i], maxTake + output[leftToTake]);
            }
        }

        return output[n];
    }
};

int main() {
    
    Solution s;

    for (int i = 10000; i >= 1; --i)
    {
        const int result = s.numSquares(i);
        cout << i << " " << result << endl;
    }
    
    return 0;
}

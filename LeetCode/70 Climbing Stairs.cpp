#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int climbStairs(int n) {
            vector<int> cache(47, 0);
            cache[0] = 1;
            cache[1] = 1;
            for (size_t i = 2; i < 46; i++)
            {
                cache[i] = cache[i - 1] + cache[i - 2];
            }

            return cache[n];
        }
};

int main() {
    Solution s;
    int answer = s.climbStairs(12);
    cout << answer << endl;
    return 0;
}
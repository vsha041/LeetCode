#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> cache(38, 0);
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;
        for (size_t i = 3; i < cache.size(); i++)
        {
            cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
        }

        return cache[n];
    }
};

int main() {
    Solution s;
    auto answer = s.tribonacci(37);
    cout << answer << endl;
    return 0;
}
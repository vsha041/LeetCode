#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size(), -1);
        int answer = findCost(cost.size(), cost, cache);
        return answer;
    }

    int findCost(int n, vector<int> &cost, vector<int> &cache)
    {
        if (n == 0 || n == 1)
            return 0;

        auto stepOneCost = cost[n - 1];
        if (cache[n - 1] == -1)
        {
            auto first = findCost(n - 1, cost, cache);
            cache[n - 1] = first;
        }        

        auto stepTwoCost = cost[n - 2];
        if (cache[n - 2] == -1)
        {
            auto second = findCost(n - 2, cost, cache);
            cache[n - 2] = second;
        }

        return min(stepOneCost + cache[n - 1], stepTwoCost + cache[n - 2]);
    }
};

int main() {
    Solution s;
    //vector<int> v{ 1,100,1,1,1,100,1,1,100,1 };
    vector<int> v{ 10, 15, 20 };
    auto answer = s.minCostClimbingStairs(v);
    cout << answer << endl;
    return 0;
}

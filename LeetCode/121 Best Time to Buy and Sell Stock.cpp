#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int profit = 0;
        for (int i = 1; i < static_cast<int>(prices.size()); ++i)
        {
            int sell = prices[i];
            if (sell - minimum > profit)
            {
                profit = sell - minimum;
            }
            minimum = min(minimum, prices[i]);
        }
        return profit;
    }
    
};

int main() {
    Solution s;
    vector<int> v{ 7,6,4,3,1 };
    auto answer = s.maxProfit(v);
    cout << answer << endl;
    return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum = sum + nums[i];

            if (sum > maximum)
                maximum = sum;

            if (sum < 0)
                sum = 0;
        }
        return maximum;
    }
    
};

int main() {
    Solution s;
    vector<int> v{ 5,4,-1,7,8 };
    auto answer = s.maxSubArray(v);
    cout << answer << endl;
    return 0;
}
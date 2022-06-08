#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> nums(n + 1, 0);
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 0; i < n + 1; ++i)
        {
            int index1 = 2 * i;
            int index2 = 2 * i + 1;
            if (index1 < n + 1)
            {
                nums[index1] = nums[i];
            }
            if (index2 < n + 1 && i + 1 < n + 1)
            {
                nums[index2] = nums[i] + nums[i + 1];
            }
        }

        return *max_element(nums.begin(), nums.end());
    }
    
};

int main() {
    Solution s;
    auto answer = s.getMaximumGenerated(3);
    cout << answer << endl;
    return 0;
}
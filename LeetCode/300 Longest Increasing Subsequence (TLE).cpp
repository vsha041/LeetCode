#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int> > cache(nums.size(), vector<int>(nums.size(), -1));
        int result = solve(nums, 0, -1, cache);
        return result;
    }

    int solve(vector<int>& nums, int currentIndex, int prevIndex, vector<vector<int> >& cache) {
        if (currentIndex == nums.size()) {
            return 0;
        }

        if (prevIndex != -1 && cache[currentIndex][prevIndex] != -1) {
            return cache[currentIndex][prevIndex];
        }

        int result1 = 0;
        if (prevIndex == -1 || nums[currentIndex] > nums[prevIndex]) {
            result1 = 1 + solve(nums, currentIndex + 1, currentIndex, cache);
        }
        int result2 = solve(nums, currentIndex + 1, prevIndex, cache);
        if (prevIndex != -1)
            cache[currentIndex][prevIndex] = max(result1, result2);
        return max(result1, result2);
    }
	
	void print(const vector<int> &v){
        for (auto i = v.begin(); i != v.end(); ++i)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;
		
    vector<int> v{ 10,9,2,5,3,7,101,18 };
    int result = s.lengthOfLIS(v);
    cout << result << endl;

    return 0;
}

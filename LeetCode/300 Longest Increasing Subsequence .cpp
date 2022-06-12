#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        int largest = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int current = nums[i];
            for (size_t j = 0; j < i; j++)
            {                
                if (nums[i] > nums[j] && output[i] < output[j] + 1){
                    output[i] = output[j] + 1;
                    largest = max(output[i], largest);
                }
            }
        }

        return largest;
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
	
	// ANSWER = 80
    vector<int> v{ 10,9,2,5,3,7,101,18 };
    int result = s.lengthOfLIS(v);
    cout << result << endl;

    return 0;
}

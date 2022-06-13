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
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> answer(nums.size(), 0);
        answer[0] = nums[0];
        answer[1] = nums[1];
        for (int i = 2; i < nums.size(); ++i)
        {
            answer[i] = nums[i];
            const auto maxElement = *max_element(answer.begin(), answer.begin() + i - 1);
            if (answer[i] + maxElement > answer[i])
                answer[i] = answer[i] + maxElement;
        }

        return *max_element(answer.begin(), answer.end());
    }
};

vector<int> generate_random_numbers(int n) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(0, 400); // define the range
    vector<int> range;
    for (int i = 0; i < n; i++)
    {
        range.emplace_back(distr(gen));
    }

    return range;
}

void print(const vector<int>& v) {
    for (const auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {
    vector<int> range = generate_random_numbers(100);
    print(range);
    Solution s;
    const int result = s.rob(range);
    cout << result << endl;

    return 0;
}

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; ++i)
        {
            result.emplace_back(__builtin_popcount(i));
        }

        return result;
    }
};
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > answer(numRows, vector<int>());

        if (numRows == 1)
        {
            answer[0] = vector<int>{ 1 };
            return answer;
        }

        if (numRows == 2)
        {
            answer[0] = vector<int>{ 1 };
            answer[1] = vector<int>{ 1, 1 };
            return answer;
        }

        answer[0] = vector<int>{ 1 };
        answer[1] = vector<int>{ 1, 1 };

        for (size_t i = 2; i < answer.size(); i++)
        {
            answer[i].resize(i + 1, 0);
            vector<int>& row = answer[i];
            for (size_t j = 0; j < row.size(); j++)
            {
                if (j == 0 || j == row.size() - 1)
                {
                    row[j] = 1;
                }
                else
                {
                    vector<int>& previous = answer[i - 1];
                    row[j] = previous[j - 1] + previous[j];
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution s;
    auto answer = s.generate(30);
    return 0;
}
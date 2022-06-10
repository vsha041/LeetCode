#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int closed = 0;
        vector<string> v;
        solve(open, closed, "", n * 2, v);
        return v;
    }

    void solve(int open, int closed, string current, const int &maxLength, vector<string> &v)
    {
        if (current.length() == maxLength) {
            v.emplace_back(current);
            return;
        }

        if (open < maxLength / 2)
        {
            // u can add open
            solve(open + 1, closed, current + "(", maxLength, v);
        }
        if (closed < open)
        {
            // u can add closed
            solve(open, closed + 1, current + ")", maxLength, v);
        }
    }

    void print(vector<vector<int> > &v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }

    void print(vector<string> &v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    auto answer = s.generateParenthesis(3);
    s.print(answer);

    return 0;
}
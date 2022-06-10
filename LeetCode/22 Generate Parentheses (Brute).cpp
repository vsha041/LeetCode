#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool isValid(string s)
    {
        stack<char> stack;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                stack.push(s[i]);
            }
            else if (s[i] == ')' && stack.empty())
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }

        return stack.empty();
    }

    vector<string> generateParenthesis(int n) {
        int cases = 1 << (n*2);
        vector<string> v;

        for (int i = 0; i < cases; ++i)
        {
            string s("");
            for (int j = 0; j < n * 2; ++j)
            {
                if (((1 << j) & i) == 0) {
                    s.append("(");
                    continue;
                }
                s.append(")");
            }
            if (isValid(s))
                v.emplace_back(s);
        }
        return v;
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
    auto answer = s.generateParenthesis(8);
    s.print(answer);

    return 0;
}
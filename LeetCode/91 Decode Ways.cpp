/*
to find the answer for a given index, you can either 
-use the previous digit directly by taking the previous answer and for each one separating by comma
-combine the previous digit with the second previous digit and see if that fits the answer and if it does you just take the previous to previous answer and add 1 to it

but note that for the above 2 cases, you will need to handle 0 separately for each one.

*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

        int answer = solve2(s);
        return answer;
    }

    int string2int(string s) {
        stringstream ss;
        int num;
        ss << s;
        ss >> num;
        return num;
    }

    int solve2(string s) {
        if (s[0] == '0')
            return 0;

        if (s.length() == 1)
            return 1;

        if (s.length() == 2) {
            int num = string2int(s);
            if (num == 10 || num == 20)
                return 1;
            if (num % 10 == 0)
                return 0;
            if (num > 26)
                return 1;

            return 2;
        }

        vector<int> answer(s.length(), 0);
        answer[0] = 1;
        string temp = string() + s[0] + s[1];
        int num = string2int(temp);
        if (num == 10 || num == 20)
            answer[1] = 1;
        else if (num < 27)
            answer[1] = 2;
        else if (num % 10 == 0)
            answer[1] = 0;
        else if (num > 26)
            answer[1] = 1;
        else
            answer[1] = 1;

        for (size_t i = 2; i < s.size(); i++)
        {
            if (s[i] != '0') {
                answer[i] = answer[i - 1];
                if (s[i - 1] == '0')
                    continue;
                int num = string2int(string() + s[i - 1] + s[i]);
                if (num < 27)
                    answer[i] = answer[i] + answer[i - 2];
            }
            else {
                int num = string2int(string() + s[i - 1] + s[i]);
                if (s[i - 1] == '0')
                    continue;
                if (num < 27)
                    answer[i] = answer[i] + answer[i - 2];
            }
        }

        return answer[answer.size() - 1];
    }
};

int main() {
    Solution s;    
    vector<string> cases{ "611", "27", "301", "30" };
    for (size_t i = 0; i < cases.size(); i++)
    {
        int result = s.numDecodings(cases[i]);
        cout << cases[i] << " " << result << endl;
    }

    return 0;
}

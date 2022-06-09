#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<char> vowels{ 'a', 'e', 'i', 'o', 'u' };
        map<char, int> m;
        for (int i = 0; i < vowels.size(); ++i)
            m[vowels[i]] = i;

        int answer = 0;

        solve(answer, n, "", m, vowels);

        return answer;
    }

    void solve(int &answer, int length, string currentString, map<char, int> &m, vector<char> &vowels)
    {
        if (currentString.length() > 0 && currentString.length() == length){
                return;
        }

        for (int i = 0; i < vowels.size() && currentString.size() <= length - 1; ++i)
        {
            auto temp = currentString + vowels[i];
            if (temp.size() > length || (!currentString.empty() && m[currentString[currentString.size() - 1]] > m[vowels[i]]))
                continue;

            currentString.push_back(vowels[i]);
            if (currentString.size() == length)
            {
                ++answer;
            }
            solve(answer, length, currentString,  m, vowels);
            currentString.erase(currentString.size() - 1, 1);
        }
    }
};

int main() {
    Solution s;
    for (int i = 1; i < 34; ++i)
    {
        auto answer = s.countVowelStrings(i);
        cout << answer << endl;
    }
    
    
    return 0;
}
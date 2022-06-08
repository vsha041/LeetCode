#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())
            return false;

        int i = 0, j = 0;
        while(j < s.length() && i < t.length())
        {
            if (s[j] == t[i])
            {
                j++;
                i++;
            }
            else
            {
                i++;
            }
        }

        return j == s.length();
    }
    
};

int main() {
    Solution s;
    auto answer = s.isSubsequence("abc", "ahbgdc");
    auto answer2 = s.isSubsequence("axc", "ahbgdc");
    auto answer3 = s.isSubsequence("axcggretrtterter", "ahbgdc");
    auto answer4 = s.isSubsequence("axc", "axc");
    auto answer5 = s.isSubsequence("axc", "aaaaxxxxxcccccc");
    auto answer6 = s.isSubsequence("axcd", "axc");
    auto answer7 = s.isSubsequence("gfpngz", "gfdgegerpmnknfdegzg");
    cout << answer << endl;
    return 0;
}
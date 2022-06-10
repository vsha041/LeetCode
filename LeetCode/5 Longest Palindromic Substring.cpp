#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		size_t length = s.size();
		string answer1 = oddLengthPalindrome(s);
		string answer2 = evenLengthPalindrome(s);
		if (answer1.size() > answer2.size()) 
			return answer1;

	    return answer2;
	}

	string oddLengthPalindrome(string s) {
		int bestLower = -1, bestUpper = -1, difference = -1;
		int size = int(s.length());
		for (int i = 0; i < size; i++) {
			int lower = i, upper = i;
			while (true) {
				if (lower >= 0 && upper < size && s[lower] == s[upper]) {
					--lower, ++upper;
					continue;
				}
				if (--upper - ++lower + 1 > difference) {
					bestLower = lower, bestUpper = upper, difference = upper - lower + 1;
				}
				break;
			}
		}
		return s.substr(bestLower, difference);
	}

	string evenLengthPalindrome(string s) {
		int bestLower = -1, bestUpper = -1, difference = -1;
		int size = int(s.length());
		for (int i = 0; i < size; i++) {
			int lower = i - 1, upper = i;
			while (true) {
				if (lower >= 0 && upper < size && s[lower] == s[upper]) {
					--lower, ++upper;
					continue;
				}
				if (--upper - ++lower + 1 > difference) {
					bestLower = lower, bestUpper = upper, difference = upper - lower + 1;
				}
				break;
			}
		}
		return s.substr(bestLower, difference);
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
};

int main() {
    Solution s;
    auto answer = s.longestPalindrome("aba");
    cout << answer << endl;

    return 0;
}
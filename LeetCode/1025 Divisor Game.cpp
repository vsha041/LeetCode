#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        vector<int> state(1001, -1);
        canWin(n, state);
        if (state[n] == 1)
            return true;
        return false;
    }

    bool canWin(int n, vector<int> &state)
    {
        if (n <= 1)
            return false;

        if (state[n] != -1)
            return state[n];

        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                const bool result = canWin(n - i, state);
                if (result == false) {
                    state[n] = true;
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    bool divisor_game = s.divisorGame(4);
    cout << divisor_game << endl;
    return 0;
}
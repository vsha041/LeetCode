#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <sstream>
#include <random>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1)
            return false;

        if (n == 1)
            return true;

        if (n == 0)
            return false;

        if (n % 4 >= 1 && n % 4 <= 3)
            return false;

        const auto result = isPowerOfFour(n / 4);
        return result;        
    }
};

int main() {

    Solution s;
    const auto ln1 = new ListNode(1);
    const auto ln2 = new ListNode(2);
    const auto ln3 = new ListNode(2);
    const auto ln4 = new ListNode(1);

    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln4;
    ln4->next = nullptr;

    const bool result2 = s.isPowerOfFour(6);

    for (int i = 0; i < 100000; ++i)
    {
        const bool result = s.isPowerOfFour(i);
        if (result)
            cout << i << " "<< result << endl;
    }
    
    return 0;
}

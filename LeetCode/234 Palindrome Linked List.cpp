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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        string s;
        s.reserve(10000 + 10);
        traverse(head, s);

        string t(s.begin(), s.end());
        reverse(t.begin(), t.end());
        return s == t;
    }

    void traverse(const ListNode* head, string &s) const
    {
        if (head == nullptr)
            return;

        const auto temp = to_string(head->val);
        s.append(temp);
        traverse(head->next, s);
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

    const bool result = s.isPalindrome(ln1);
    cout << result << endl;
    return 0;
}

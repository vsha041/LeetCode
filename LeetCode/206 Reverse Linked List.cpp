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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr)
            return head;

        const auto result = reverseList3(head);
        return result;
    }
    
    ListNode* reverseList3(ListNode* head) {
        ListNode* prev = nullptr;
        auto i = head;
        const auto tracker = new ListNode();

        while(i != nullptr)
        {
            const auto newNode = new ListNode(i->val);
            newNode->next = prev;            
            tracker->next = newNode;
            i = i->next;
            prev = newNode;
        }

        return tracker->next;
    }    
};

int main() {

    Solution s;
    ListNode* ln1 = new ListNode(1);
    ListNode* ln2 = new ListNode(2);
    ListNode* ln3 = new ListNode(3);
    ListNode* ln4 = new ListNode(4);

    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln4;
    ln4->next = nullptr;

    ListNode* result = s.reverseList3(ln1);
    while(result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}

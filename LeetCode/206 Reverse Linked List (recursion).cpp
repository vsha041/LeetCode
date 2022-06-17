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

        ListNode* prev = nullptr;
        const auto tracker = new ListNode();
        reverse_list_2(head, prev, tracker);
        return tracker->next;
    }
    
    static void reverse_list_2(const ListNode* head, ListNode* prev, ListNode* tracker)
    {
        if (head == nullptr)
            return;

        const auto newNode = new ListNode(head->val, prev);
        tracker->next = newNode;
        reverse_list_2(head->next, newNode, tracker);        
    }
};

int main() {

    Solution s;
    const auto ln1 = new ListNode(1);
    const auto ln2 = new ListNode(2);
    const auto ln3 = new ListNode(3);
    const auto ln4 = new ListNode(4);

    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln4;
    ln4->next = nullptr;

    const ListNode* result = s.reverseList(ln1);
    while(result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}

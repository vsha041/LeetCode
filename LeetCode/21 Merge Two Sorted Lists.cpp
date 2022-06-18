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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;

        auto i = new ListNode(0, nullptr);
        auto answer = new ListNode(0, i);
        

        while(list1 != nullptr && list2 != nullptr)
        {
            if (list1->val == list2->val)
            {
                const auto node1 = new ListNode(list1->val, nullptr);
                const auto node2 = new ListNode(list2->val, nullptr);
                node1->next = node2;
                i->next = node1;
                i = i->next;
                i->next = node2;
                i = i->next;
                list1 = list1->next;
                list2 = list2->next;
            }
            else if(list1->val < list2->val)
            {
                const auto node = new ListNode(list1->val, nullptr);
                i->next = node;
                i = i->next;
                list1 = list1->next;
            }
            else
            {
                const auto node = new ListNode(list2->val, nullptr);
                i->next = node;
                i = i->next;
                list2 = list2->next;
            }
        }

        while(list1 != nullptr)
        {
            const auto node = new ListNode(list1->val, nullptr);
            i->next = node;
            i = i->next;
            list1 = list1->next;
        }

        while (list2 != nullptr)
        {
            const auto node = new ListNode(list2->val, nullptr);
            i->next = node;
            i = i->next;
            list2 = list2->next;
        }

        return answer->next->next;
    }
};

int main() {

    Solution s;
    const auto ln1 = new ListNode(1);
    const auto ln2 = new ListNode(2);
    const auto ln3 = new ListNode(2);
    const auto ln4 = new ListNode(4);

    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln4;
    ln4->next = nullptr;

    const auto n1 = new ListNode(1);
    const auto n2 = new ListNode(2);
    const auto n3 = new ListNode(2);
    const auto n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;

    const ListNode* result = s.mergeTwoLists(ln1, n1);
    while(result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}

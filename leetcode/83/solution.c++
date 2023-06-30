#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head) {
        if (nullptr == head) {
            return head;
        }
        ListNode* ret    = head;
        ListNode* curr   = ret;
        ListNode* cursor = head->next;
        while (nullptr != cursor) {
            if (curr->val == cursor->val) {
                cursor = cursor->next;
                continue;
            }

            curr->next = cursor;
            cursor     = cursor->next;
            curr       = curr->next;
            curr->next = nullptr;
        }
        curr->next = nullptr;
        return ret;
    }
};

static void fill_list(ListNode* list, std::vector<int> data) {
    ListNode* curr = list;
    for (auto i = 0; i < data.size(); i++) {
        curr->val = data[i];
        if (i < data.size() - 1) {
            curr->next = new ListNode();
            curr       = curr->next;
        }
    }
}

static void print_list(ListNode* list) {
    if (nullptr == list) {
        return;
    }
    ListNode* curr = list;
    while (nullptr != curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    auto l1 = std::make_unique<ListNode>();
    fill_list(l1.get(), {1, 1});
    print_list(l1.get());

    auto solution = std::make_unique<Solution>();
    auto result   = solution->mergeTwoLists(l1.get());
    print_list(result);

    std::cout << "Hello World!" << std::endl;
}

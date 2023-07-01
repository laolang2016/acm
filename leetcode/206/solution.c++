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
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head) {
            return nullptr;
        }

        auto ret    = head;
        auto cursor = head->next;
        ret->next   = nullptr;

        while (nullptr != cursor) {
            auto tmp = cursor;
            cursor = cursor->next;
            tmp->next = ret;
            ret       = tmp;
        }

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
    fill_list(l1.get(), {1, 2, 3, 4, 5, 6});
    print_list(l1.get());

    auto solution = std::make_unique<Solution>();
    auto result   = solution->reverseList(l1.get());
    print_list(result);

    std::cout << "Hello World!" << std::endl;
}

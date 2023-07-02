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

#define PRINT_LOG

class Solution {
public:
    // 计算长度
    size_t length(ListNode* head) {
        if (nullptr == head) {
            return 0;
        }
        size_t length = 0;
        auto   cursor = head;
        while (nullptr != cursor) {
            cursor = cursor->next;
            length++;
        }
        return length;
    }

    ListNode* middleNode(ListNode* head) {
        auto len = length(head);
        if (0 == len) {
            return nullptr;
        }

        auto   index  = len / 2;
        size_t i      = 0;
        auto   cursor = head;
        while (i < index) {
            cursor = cursor->next;
            i++;
        }

        return cursor;
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

void test_001() {
    std::cout << "==== test 001:" << std::endl;
    auto l1 = std::make_unique<ListNode>();
    fill_list(l1.get(), {1, 2, 3, 4, 5});

    auto solution = std::make_unique<Solution>();
    auto ret      = solution->middleNode(l1.get());
    std::cout << "ret:" << ret->val << std::endl;
}

void test_002() {
    std::cout << "==== test 002:" << std::endl;
    auto l1 = std::make_unique<ListNode>();
    fill_list(l1.get(), {1, 2, 3, 4, 5, 6});

    auto solution = std::make_unique<Solution>();
    auto ret      = solution->middleNode(l1.get());
    std::cout << "ret:" << ret->val << std::endl;
}

int main() {
    system("chcp 65001");
    test_001();
    test_002();
    std::cout << "Hello World!" << std::endl;
}

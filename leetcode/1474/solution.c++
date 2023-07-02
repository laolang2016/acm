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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if (nullptr == head) {
            return head;
        }
        auto cursor = head;
        while (nullptr != cursor) {
            int  i    = 0;
            int  j    = 0;
            auto save = cursor;
            while (nullptr != save->next && i < m - 1) {
                save = save->next;
                i++;
            }
            if (nullptr == save->next) {
                break;
            }
            auto del = save->next;
            while (nullptr != del && j < n) {
                auto tmp   = del;
                del        = del->next;
                save->next = del;

                tmp->next = nullptr;
                delete tmp;
                tmp = nullptr;

                j++;
            }
            cursor = save->next;
        }
        return head;
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
    fill_list(l1.get(), {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
    print_list(l1.get());

    auto solution = std::make_unique<Solution>();
    solution->deleteNodes(l1.get(), 2, 3);
    print_list(l1.get());
}

void test_002() {
    std::cout << "==== test 002:" << std::endl;
    auto l1 = std::make_unique<ListNode>();
    fill_list(l1.get(), {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    print_list(l1.get());

    auto solution = std::make_unique<Solution>();
    solution->deleteNodes(l1.get(), 1, 3);
    print_list(l1.get());
}

int main() {
    system("chcp 65001");
    test_001();
    test_002();
    std::cout << "Hello World!" << std::endl;
}

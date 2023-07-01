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

    // 是否为偶数
    template <typename T> bool is_even_number(T num) {
        return 0 == (num & 1);
    }

    bool isPalindrome(ListNode* head) {
        // 长度为 0 直接返回 false
        auto len = length(head);
        if (0 == len) {
            return false;
        }

        // 长度为 1 , 直接返回 true
        if (1 == len) {
            return true;
        }

        // 长度为 2 , 直接比较
        if (2 == len) {
            return head->val == head->next->val;
        }

        // 长度为 3 , 直接比较
        if (3 == len) {
            return head->val == head->next->next->val;
        }

        auto len_is_even = is_even_number(len);

        // 找到左边链表尾节点
        auto half_len = len / 2;
        auto cursor   = head;
        for (size_t i = 0; i < half_len - 1; i++) {
            cursor = cursor->next;
        }
        auto left_last = len_is_even ? cursor : cursor->next;

        // 右边链表起点
        ListNode* right_start = left_last->next;
        left_last->next       = nullptr;

        // 构造右边链表
        ListNode* right_list = nullptr;
        while (nullptr != right_start) {
            auto tmp    = right_start;
            right_start = right_start->next;
            if (nullptr == right_list) {
                right_list       = tmp;
                right_list->next = nullptr;
            } else {
                tmp->next  = right_list;
                right_list = tmp;
            }
        }

#ifdef PRINT_LOG
        // 打印左右两个链表
        std::cout << "分割后的链表" << std::endl;
        print_list(head);
        print_list(right_list);
#endif

        // 比较
        bool ret          = true;
        auto cursor_left  = head;
        auto cursor_right = right_list;
        for (size_t i = 0; i < half_len; i++) {
            if (cursor_left->val != cursor_right->val) {
                ret = false;
                break;
            }
            cursor_left  = cursor_left->next;
            cursor_right = cursor_right->next;
        }

        // 还原链表
        cursor_right = right_list;
        while (nullptr != cursor_right) {
            auto tmp     = cursor_right;
            cursor_right = cursor_right->next;

            tmp->next       = left_last->next;
            left_last->next = tmp;
        }

#ifdef PRINT_LOG
        // 打印还原后的链表
        std::cout << "还原后的链表:" << std::endl;
        print_list(head);
#endif
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

static void test_even() {
    std::cout << "====> test even:" << std::endl;
    auto l1 = std::make_unique<ListNode>();
    fill_list(l1.get(), {1, 1, 2, 1});

    auto              solution = std::make_unique<Solution>();
    const std::string ret      = solution->isPalindrome(l1.get()) ? "Y" : "N";
    std::cout << "ret:" << ret << std::endl;
}

static void test_odd() {
    std::cout << "====> test odd:" << std::endl;
    auto l1 = std::make_unique<ListNode>();
    fill_list(l1.get(), {1, 2, 3, 4, 5, 4, 3, 2, 1});

    auto              solution = std::make_unique<Solution>();
    const std::string ret      = solution->isPalindrome(l1.get()) ? "Y" : "N";
    std::cout << "ret:" << ret << std::endl;
}

int main() {
    system("chcp 65001");
    test_even();
    //test_odd();
    std::cout << "Hello World!" << std::endl;
}

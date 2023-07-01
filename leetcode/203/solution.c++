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
    ListNode* removeElements(ListNode* head, int val) {
        // 头结点为 null, 返回 null
        if (nullptr == head) {
            return nullptr;
        }

        // 找到第一个不等于给定值的节点
        auto cursor = head;
        while (val == cursor->val) {
            cursor = cursor->next;
            if (nullptr == cursor) {
                break;
            }
        }
        // 如果没找到, 说明所有节点的值都等于给定值, 直接返回 null
        if (nullptr == cursor) {
            return nullptr;
        }

        // 创建一个新节点, 值为第一个不等于给定值的节点的值, 尾指针指向下一个节点
        ListNode* ret = new ListNode();
        ret->val      = cursor->val;
        ret->next     = cursor->next;

        // 循环剩余的节点
        cursor = ret;
        while (nullptr != cursor->next) {
            // 相等的节点删除
            if (val == cursor->next->val) {
                ListNode* tmp = cursor->next;
                cursor->next = tmp->next;
                tmp->next     = nullptr;
                delete tmp;
                continue;
            }

            // 不相等的跳过
            cursor = cursor->next;
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
    fill_list(l1.get(), {1,2,3,4,5,6});
    print_list(l1.get());

    auto solution = std::make_unique<Solution>();
    auto result   = solution->removeElements(l1.get(), 6);
    print_list(result);

    std::cout << "Hello World!" << std::endl;
}

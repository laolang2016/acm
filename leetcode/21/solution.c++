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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if( nullptr == list1){
            return list2;
        }
 
        if( nullptr == list2){
            return list1;
        }

        // l1 头节点不大于 l2 头结点
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        if (list1->val > list2->val) {
            l1 = list2;
            l2 = list1;
        }

        // 开始插入
        ListNode* cursor = l1;
        while (nullptr != l2) {
            // 去除当前要插入的节点
            ListNode* tmp = l2;
            l2            = l2->next;

            // 找到 l1 中不大于当前插入节点的最后一个节点
            while (nullptr != cursor->next && cursor->next->val <= tmp->val) {
                cursor = cursor->next;
            }
            // 如果已经到 l1 尾部, 直接把 l2 拼接到 l1 后面, 合并结束
            if (nullptr == cursor->next) {
                cursor->next = tmp;
                break;
            }

            // 把当前插入节点追加到 l1 , 并把游标设置为当前插入节点
            tmp->next    = cursor->next;
            cursor->next = tmp;
            cursor       = tmp;
        }

        return l1;
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
    fill_list(l1.get(), {2, 5, 8});
    print_list(l1.get());

    auto l2 = std::make_unique<ListNode>();
    fill_list(l2.get(), {3, 4, 8, 9});
    print_list(l2.get());

    auto solution = std::make_unique<Solution>();
    auto result   = solution->mergeTwoLists(l1.get(), l2.get());
    print_list(result);

    std::cout << "Hello World!" << std::endl;
}

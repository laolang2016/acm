package com.laolang.leetcode;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
public class Solution {

    public ListNode deleteNodes(ListNode head, int m, int n) {
        if (null == head) {
            return null;
        }
        ListNode cursor = head;
        while (null != cursor) {
            int i = 0;
            int j = 0;
            ListNode save = cursor;
            while (null != save.next && i < m - 1) {
                save = save.next;
                i++;
            }
            if (null == save.next) {
                break;
            }
            ListNode del = save.next;
            while (null != del && j < n) {
                del = del.next;

                save.next = del;

                j++;
            }
            cursor = save.next;
        }

        return head;
    }
}

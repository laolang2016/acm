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

    public int length(ListNode head) {
        if (null == head) {
            return 0;
        }
        int length = 0;
        ListNode cursor = head;
        while (null != cursor) {
            cursor = cursor.next;
            length++;
        }
        return length;
    }


    public ListNode middleNode(ListNode head) {
        int len = length(head);
        if (0 == len) {
            return null;
        }

        int index = len / 2;
        int i = 0;
        ListNode cursor = head;
        while (i < index) {
            cursor = cursor.next;
            i++;
        }

        return cursor;
    }
}

package com.laolang.leetcode;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
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

    public boolean isEventNumber(int num) {
        return 0 == (num & 1);
    }

    public boolean isPalindrome(ListNode head) {
        int len = length(head);
        // 链表为空, 返回 false
        if (0 == len) {
            return false;
        }
        // 链表长度为 1 , 返回 true
        if (1 == len) {
            return true;
        }
        // 链表长度为 2 或者 3 , 直接比较
        if (2 == len) {
            return head.val == head.next.val;
        }
        if (3 == len) {
            return head.val == head.next.next.val;
        }

        boolean lenIsEven = isEventNumber(len);

        // 左边链表尾节点
        int halfLen = len / 2;
        ListNode cursor = head;
        for (int i = 0; i < halfLen - 1; i++) {
            cursor = cursor.next;
        }
        ListNode leftLast = lenIsEven ? cursor : cursor.next;

        // 右边链表起点
        ListNode rightStart = leftLast.next;
        leftLast.next = null;

        // 构造右边链表
        ListNode rightList = null;
        while (null != rightStart) {
            ListNode tmp = rightStart;
            rightStart = rightStart.next;
            if (null == rightList) {
                rightList = tmp;
                rightList.next = null;
            } else {
                tmp.next = rightList;
                rightList = tmp;
            }
        }

        // 比较
        boolean ret = true;
        ListNode cursorLeft = head;
        ListNode cursortRight = rightList;
        for (int i = 0; i < halfLen; i++) {
            if (cursorLeft.val != cursortRight.val) {
                ret = false;
                break;
            }
            cursorLeft = cursorLeft.next;
            cursortRight = cursortRight.next;
        }

        // 还原链表
        cursortRight = rightList;
        while (null != cursortRight) {
            ListNode tmp = cursortRight;
            cursortRight = cursortRight.next;

            tmp.next = leftLast.next;
            leftLast.next = tmp;
        }

        return ret;
    }
}

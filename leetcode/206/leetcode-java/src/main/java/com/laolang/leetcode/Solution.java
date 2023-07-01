package com.laolang.leetcode;

import java.util.Objects;

public class Solution {

    public ListNode reverseList(ListNode head) {
        if (Objects.isNull(head)) {
            return null;
        }
        ListNode ret = head;
        ListNode cursor = head.next;
        ret.next = null;

        while (null != cursor) {
            ListNode tmp = cursor;
            cursor = cursor.next;
            tmp.next = ret;
            ret = tmp;
        }

        return ret;
    }
}

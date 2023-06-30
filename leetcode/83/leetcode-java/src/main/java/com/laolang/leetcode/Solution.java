package com.laolang.leetcode;

import java.util.Objects;

public class Solution {

    public ListNode deleteDuplicates(ListNode head) {
        if (Objects.isNull(head)) {
            return head;
        }

        ListNode ret = head;
        ListNode curr = ret;
        ListNode cursor = head;
        while (Objects.nonNull(cursor)) {
            if (curr.val == cursor.val) {
                cursor = cursor.next;
                continue;
            }

            curr.next = cursor;
            cursor = cursor.next;
            curr = curr.next;
        }
        curr.next = null;

        return ret;
    }
}

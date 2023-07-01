package com.laolang.leetcode;

import java.util.Objects;

public class Solution {

    public ListNode removeElements(ListNode head, int val) {
        if(Objects.isNull(head)){
            return null;
        }

        ListNode cursor = head;
        while(val == cursor.val){
            cursor = cursor.next;
            if( null == cursor){
                break;
            }
        }

        if( null == cursor){
            return null;
        }

        ListNode ret = new ListNode();
        ret.val = cursor.val;
        ret.next = cursor.next;

        cursor = ret;
        while( null != cursor.next){
            if( val == cursor.next.val){
                cursor.next = cursor.next.next;
                continue;
            }
            cursor = cursor.next;
        }

        return ret;
    }
}

package com.laolang.leetcode;

import java.util.Objects;

public class Solution {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if( Objects.isNull(list1)){
            return list2;
        }

        if( Objects.isNull(list2)){
            return list1;
        }

        ListNode l1 = list1;
        ListNode l2 = list2;
        if(l1.val > l2.val){
            l1 = list2;
            l2 = list1;
        }

        ListNode cursor = l1;
        while( null != l2){
            ListNode tmp = l2;
            l2 = l2.next;

            while( null != cursor.next && cursor.next.val <= tmp.val){
                cursor = cursor.next;
            }

            if( null == cursor.next){
                cursor.next = tmp;
                break;
            }

            tmp.next = cursor.next;
            cursor.next = tmp;
            cursor = tmp;
        }
        return l1;
    }
}

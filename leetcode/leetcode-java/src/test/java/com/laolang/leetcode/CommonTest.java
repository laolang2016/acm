package com.laolang.leetcode;

import java.util.List;
import java.util.Objects;
import org.testng.annotations.BeforeClass;
import org.testng.annotations.Test;
import org.testng.collections.Lists;

public class CommonTest {

    private Solution solution;
    private ListNode list1;
    private ListNode list2;


    private void fillList(ListNode list, List<Integer> data){
        ListNode node = list;
        for (int i = 0; i < data.size(); i++) {
            node.val =  data.get(i);
            if( i < data.size() - 1){
                node.next = new ListNode();
                node = node.next;
            }
        }
    }

    @BeforeClass
    public void beforeClass(){
        solution = new Solution();
        list1 = new ListNode();
        list2 = new ListNode();
        fillList(list1, Lists.newArrayList(1,2,3));
        fillList(list2, Lists.newArrayList(1,3,4));
    }

    private void printList(ListNode list){
        if(Objects.isNull(list) ){
            return ;
        }
        ListNode curr = list;
        while( Objects.nonNull(curr)){
            System.out.print(curr.val);
            System.out.print(" ");
            curr = curr.next;
        }
        System.out.println();
    }

    @Test
    public void testOne(){
        printList(list1);
        printList(list2);

        ListNode ret = solution.mergeTwoLists(list1,list2);
        printList(ret);
    }
}

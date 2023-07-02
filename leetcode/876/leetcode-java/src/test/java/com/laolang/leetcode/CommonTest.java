package com.laolang.leetcode;

import java.util.List;
import java.util.Objects;
import org.testng.annotations.BeforeClass;
import org.testng.annotations.Test;
import org.testng.collections.Lists;

public class CommonTest {

    private Solution solution;
    private ListNode list1;


    private void fillList(ListNode list, List<Integer> data) {
        ListNode node = list;
        for (int i = 0; i < data.size(); i++) {
            node.val = data.get(i);
            if (i < data.size() - 1) {
                node.next = new ListNode();
                node = node.next;
            }
        }
    }

    @BeforeClass
    public void beforeClass() {
        solution = new Solution();
        list1 = new ListNode();
        fillList(list1, Lists.newArrayList(1, 2, 3, 4, 5, 6));
    }

    private void printList(ListNode list) {
        if (Objects.isNull(list)) {
            return;
        }
        ListNode curr = list;
        while (Objects.nonNull(curr)) {
            System.out.print(curr.val);
            System.out.print(" ");
            curr = curr.next;
        }
        System.out.println();
    }

    @Test
    public void testOne() {
        printList(list1);
        ListNode ret = solution.middleNode(list1);
        System.out.println(ret.val);
    }
}

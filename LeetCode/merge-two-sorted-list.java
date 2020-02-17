/**
 * Definition for singly-linked list.
 */
class Solution {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode mergeTwoLists(ListNode temp1, ListNode temp2) {
        ListNode l3 = null;
        // ListNode temp1 = l1;
        // ListNode temp2 = l2;
        ListNode temp3 = null;
        while (temp1 != null && temp2 != null) {
            ListNode current;
            if (temp1.val <= temp2.val) {
                current = temp1;
                temp1 = temp1.next;
            } else {
                current = temp2;
                temp2 = temp2.next;
            }

            if (temp3 == null) {
                l3 = current;
                temp3 = current;
            } else {
                temp3.next = current;
                temp3 = temp3.next;
            }

        }

        while (temp1 != null) {
            if (temp3 == null) {
                l3 = temp1;
                temp3 = temp1;
                temp1 = temp1.next;
            } else {
                temp3.next = temp1;
                temp1 = temp1.next;
                temp3 = temp3.next;
            }
        }

        while (temp2 != null) {
            if (temp3 == null) {
                l3 = temp2;
                temp3 = temp2;
                temp2 = temp2.next;
            } else {
                temp3.next = temp2;
                temp2 = temp2.next;
                temp3 = temp3.next;
            }

        }
        return l3;
    }
}
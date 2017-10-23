// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.

//use 2 pointor, when fast one reach end, slow one reach the target.
//pay attention to head and how to chang pointor value.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, **slow=&head;
        for(int i = 0; i < n-1; i++){
            fast = fast->next;
        }

        while(fast->next){
            fast = fast->next;
            slow = &((*slow)->next);
        }

        *slow = (*slow)->next;//important
        return head;
    }
};
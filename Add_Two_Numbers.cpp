// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        int offset = 0;
        ListNode *l1_current = l1;
        ListNode *l2_current = l2;
        ListNode *head = NULL, *current = NULL;
        while(l1_current || l2_current){
            int sum = 0, result = 0;
            if(!l1_current){
                sum = l2_current->val;
                l2_current = l2_current->next;
            }
            else if(!l2_current){
                sum = l1_current->val;
                l1_current = l1_current->next;
            }
            else{
                sum = l1_current->val + l2_current->val;
                l1_current = l1_current->next;
                l2_current = l2_current->next;
            }
            
            result = sum + offset;
            offset = result/10;
            if(!head){
                head = new ListNode(result%10);
                current = head;
            }
            else{
                current->next = new ListNode(result%10);
                current = current->next;
            }
        }
        
        if(offset){
            current->next = new ListNode(offset);
            current = current->next;
        }
        
        return head;
    }
};
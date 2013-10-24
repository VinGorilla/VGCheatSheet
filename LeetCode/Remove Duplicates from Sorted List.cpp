// Remove Duplicates from Sorted List  

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return NULL;
        
        ListNode *n1 = head;
        ListNode *n2 = head->next;
        
        while(n2) {
            if(n1->val == n2->val) {
                n1->next = n2->next;
                delete n2;
                n2 = n1->next;
            } else {
                n1 = n2;
                n2 = n2->next;
            }
        }
        
        return head;
    }
};
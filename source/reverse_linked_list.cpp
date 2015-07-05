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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nex = head->next;
        
        while(1){
            cur->next = pre;
            pre = cur;
            cur = nex;
            if(cur == NULL)
                break;
            nex = cur->next;
        }
        
        return pre;
    }
};
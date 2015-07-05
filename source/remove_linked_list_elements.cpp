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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        if(head->val == val){
            ListNode* tmp = head->next;
            delete head;
            return removeElements(tmp, val);
        }
            
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != NULL){
            if(cur->val == val){
                pre->next = cur->next;
                delete cur;
            }
            else{
                pre = cur;
            }
            cur = pre->next;
        }
        
        return head;
    }
};
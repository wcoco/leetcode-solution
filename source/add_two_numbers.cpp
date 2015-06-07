#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *sum = (ListNode*)malloc(sizeof(ListNode));
		sum->val = (l1->val + l2->val) % 10;
		int carry = (l1->val + l2->val) / 10;
		ListNode *current_sum = sum;
		ListNode *current_l1 = l1->next;
		ListNode *current_l2 = l2->next;
		while (current_l1 != NULL && current_l2 != NULL)
		{
			ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
			tmp->val = (current_l1->val + current_l2->val + carry) % 10;
			carry = (current_l1->val + current_l2->val + carry) / 10;
			current_sum->next = tmp;
			current_sum = current_sum->next;
			current_l1 = current_l1->next;
			current_l2 = current_l2->next;
		}


		while (current_l1 != NULL)
		{
			ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
			tmp->val = (current_l1->val + carry) % 10;
			carry = (current_l1->val + carry) / 10;
			current_sum->next = tmp;
			current_sum = current_sum->next;
			current_l1 = current_l1->next;
		}

		while (current_l2 != NULL)
		{
			ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
			tmp->val = (current_l2->val + carry) % 10;
			carry = (current_l2->val + carry) / 10;
			current_sum->next = tmp;
			current_sum = current_sum->next;
			current_l2 = current_l2->next;
		}

		if (carry != 0)
		{
			ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
			tmp->val = carry;
			current_sum->next = tmp;
			current_sum = current_sum->next;
		}

		current_sum->next = NULL;

		return sum;
	}
};
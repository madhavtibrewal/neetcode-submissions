/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;

        while(l1 || l2 || carry != 0){
            int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            cur->next = temp;
            cur = temp;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return ans->next;
    }
};

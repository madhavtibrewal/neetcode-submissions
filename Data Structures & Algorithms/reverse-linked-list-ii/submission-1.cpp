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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* first = head;
        ListNode* prev = new ListNode(0, head);
        ListNode* temp1 = prev;

        for(int i = 1; i < left; i++){
            prev = prev->next;
        }

        ListNode* leftNode = prev;

        first = prev->next;

        ListNode* cur = first;
        while(left <= right){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            left++;
        }
        first->next = cur;
        leftNode->next = prev;
        return temp1->next;
    }
};
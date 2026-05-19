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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* prev;
        ListNode* temp;

        prev = head;
        head = head->next;
        prev->next = NULL;

        /*
            0 -> 1 -> 2 -> 3

        
        */

        while(head != NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }
};

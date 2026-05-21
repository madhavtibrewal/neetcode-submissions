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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        int n = lists.size();
        ListNode* first = lists[0];

        for(int i = 1; i < n; i++){
            ListNode* second = lists[i];
            ListNode* newList = new ListNode(0);
            ListNode* cur = newList;
            while(first && second){
                if(first->val <= second->val){
                    newList->next = first;
                    first = first->next;
                }
                else{
                    newList->next = second;
                    second = second->next;
                }
                newList = newList->next;
            }

            if(first){
                newList->next = first;
            }
            if(second){
                newList->next = second;
            }

            first = cur->next;
        }

        return first;
    }
};

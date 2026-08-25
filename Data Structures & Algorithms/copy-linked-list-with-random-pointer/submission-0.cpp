/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> vis;
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        if(vis.count(head)) return vis[head];

        Node* copy = new Node(head->val);
        vis[head] = copy;

        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);

        return copy;
    }
};

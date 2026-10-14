class Node {
public:
    int key;
    int val;
    Node* left;
    Node* right;

    Node(int k, int v): key(k), val(v), left(nullptr), right(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> keyMap;
    int capacity;
    Node* head;
    Node* tail;

    void remove(Node* node){
        Node* prev = node->left;
        Node* next = node->right;
        prev->right = next;
        next->left = prev;
    }

    void insert(Node* node){
        Node* prev = tail->left;
        prev->right = node;
        node->left = prev;
        node->right = tail;
        tail->left = node;
    }

public:

    LRUCache(int cap) {
        capacity = cap;        
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        if(keyMap.count(key)){
            Node* node = keyMap[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyMap.count(key)){
            remove(keyMap[key]);
        }

        Node* newNode = new Node(key, value);
        keyMap[key] = newNode;
        insert(newNode);

        if(keyMap.size() > capacity){
            Node* lru = head->right;
            remove(lru);
            keyMap.erase(lru->key);
            delete lru;
        }
        
    }
};

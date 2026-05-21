class Node{
    public:
        int key;
        int value;
        Node* left;
        Node* right;

        Node(int k, int v){
            key = k;
            value = v;
        }
};

class LRUCache {
public:
    unordered_map<int, Node*> keyMap;
    int capacity;
    Node* head = new Node(0, 0);
    Node* tail = new Node(0, 0);

    void insert(Node* node){
        Node* prev = tail->left;
        prev->right = node;
        node->left = prev;
        node->right = tail;
        tail->left = node;
    }

    void remove(Node* node){
        Node* prev = node->left;
        Node* next = node->right;
        prev->right = next;
        next->left = prev;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        if(keyMap.find(key) != keyMap.end()){
            Node* node = keyMap[key];
            remove(node);
            insert(node);
        return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyMap.find(key) != keyMap.end()){
            remove(keyMap[key]);
        }

        Node* newNode = new Node(key, value);
        insert(newNode);
        keyMap[key] = newNode;

        if(keyMap.size() > capacity){
            Node* LRU = head->right;
            remove(LRU);
            keyMap.erase(LRU->key);
            delete LRU;
        }
    }
};

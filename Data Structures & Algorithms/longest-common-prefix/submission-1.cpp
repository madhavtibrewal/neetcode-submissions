class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;

    Trie(){
    root = new TrieNode();
}

    void insert(const string& word){
    TrieNode* node = root;
    for(char c : word){
        if(!node->children.count(c)){
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
}

int lcp(const string& word){
    TrieNode* node = root;
    int len = 0;
    for(char c : word){
        if(!node->children.count(c)){
            return len;
        }
        len++;
        node = node->children[c];
    }
    return len;
}
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int mini = 0;
        for(int i = 1; i < n; i++){
            if(strs[mini].size() > strs[i].size()){
                mini = i;
            }
        }

        Trie trie;
        trie.insert(strs[mini]);

        int prefix = strs[mini].size();

        for(int i = 1; i < n; i++){
            prefix = min(trie.lcp(strs[i]), prefix);
        }

        return strs[mini].substr(0,prefix);

    }
};
class TrieNode{
public:
    vector<TrieNode*> children;
    bool endOfWord;

    TrieNode() : children(26, NULL), endOfWord(false){}
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(cur->children[c - 'a'] == NULL){
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* cur = root;

        for(int i = j; i < word.size(); i++){
            char c = word[i];

            if(c == '.'){
                for(TrieNode* child : cur->children){
                    if(child != NULL && dfs(word, i + 1, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(cur->children[c - 'a'] == NULL){
                    return false;
                }
                cur = cur->children[c - 'a'];
            }
        }

        return cur->endOfWord;
    }


};

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(string w : words){
            for(char c : w){
                adj[c];
                indegree[c] = 0;
            }
        }

        for(int i = 0; i < n - 1; i++){
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            if(w1.size() > w2.size() && w1.starts_with(w2)){
                return "";
            }

            for(int j = 0; j < minLen; j++){
                if(w1[j] != w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;

        for(auto& [c, deg] : indegree){
            if(deg == 0) q.push(c);
        }

        string res;

        while(!q.empty()){
            char c = q.front();
            q.pop();

            res += c;

            for(char nei : adj[c]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        return res.size() == indegree.size() ? res : "";
    }
};

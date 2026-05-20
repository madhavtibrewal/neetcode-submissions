class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<pair<int,int>> sorted;
        int n = timestamp.size();
        for(int i = 0; i < n; i++){
            sorted.push_back({timestamp[i], i});
        }

        sort(sorted.begin(), sorted.end(), [](auto& a, auto& b){return a.first < b.first;});
        unordered_map<string, vector<string>> userMap;
        for(auto& [t, idx] : sorted){
            userMap[username[idx]].push_back(website[idx]);
        }
        map<string, int> count;

        for(auto& [k, v] : userMap){
            unordered_set<string> pattern;
            int size = v.size();
            for(int i = 0; i < size - 2; i++){
                for(int j = i + 1; j < size - 1; j++){
                    for(int k = j + 1; k < size; k++){
                        string c = v[i] + "#" + v[j] + "#" + v[k] + "#";
                        pattern.insert(c);
                    }
                }
            }
            for(auto& p : pattern){
                count[p]++;
            }
        }
        pair<string, int> res = {"", INT_MIN};
        for(auto& [p, c] : count){
            if(c > res.second || (c == res.second && (res.first.empty() || p < res.first))){
                res = {p, c};
            }
        }

        vector<string> ans;
        string web = "";
        for(char c : res.first){
            if(c == '#') {
                ans.push_back(web);
                web = "";
            }
            else{
                web += c;
            }
        }

        return ans;
    }
};
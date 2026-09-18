class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis;
        for(string s : deadends){
            vis.insert(s);
        }

        if(vis.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        vis.insert("0000");

        while(!q.empty()){
            auto [curr, count] = q.front();
            q.pop();

            if(curr == target) return count;

            for(int i = 0; i < 4; i++){
                string down = curr;
                string up = curr;

                if(curr[i] == '9'){
                    down[i] = '0';
                }
                else{
                    down[i] = curr[i] + 1;
                }

                if(curr[i] == '0'){
                    up[i] = '9';
                }
                else{
                    up[i] = curr[i] - 1;
                }

                if(!vis.count(down)){
                    vis.insert(down);
                    q.push({down, count + 1});
                }

                if(!vis.count(up)){
                    vis.insert(up);
                    q.push({up, count + 1});
                }  
            }
        }

        return -1;
    }
};
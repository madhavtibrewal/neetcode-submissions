class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int farthest = 0;
        queue<int> q;
        
        if(s[n - 1] == '1') return false;

        q.push(0);
        // 0 1 2 3 4 5 6 7
        // 0 0 1 1 0 0 1 0
        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(i == n - 1) return true;

            int j = max(farthest + 1, i + minJump);
            farthest = i + maxJump;
            while(j <= farthest && j < n){
                if(s[j] == '0')
                    q.push(j);
                j++;
            }
        }

        return false;
    }
};
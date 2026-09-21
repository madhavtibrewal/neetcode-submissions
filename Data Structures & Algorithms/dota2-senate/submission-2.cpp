class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq;
        queue<int> dq;

        int n = senate.size();

        for(int i = 0; i < n; i++){
            if(senate[i] == 'R'){
                rq.push(i);
            }
            else{
                dq.push(i);
            }
        }

        while(!rq.empty() && !dq.empty()){
            int r = rq.front();
            int d = dq.front();
            rq.pop();
            dq.pop();

            if(r < d){
                rq.push(r + n);
            }
            else{
                dq.push(d + n);
            }
        }

        return  dq.empty() ? "Radiant" : "Dire";
    }
};
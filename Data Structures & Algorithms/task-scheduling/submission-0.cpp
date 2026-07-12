class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        priority_queue<int> maxHeap;

        for(auto& t : tasks){
            count[t - 'A']++;
        }

        for(auto& c : count){
            if(c > 0)
                maxHeap.push(c);
        }

        queue<pair<int, int>> q;
        int time = 0;

        while(!maxHeap.empty() || !q.empty()){
            time++;
            if(!maxHeap.empty()){
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt > 0){
                    q.push({cnt, time + n});
                }
            }
            else{
                time = q.front().second;
            }

            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;

    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        for(int i = 0; i < n; i++){
            indices[i] = i;
        }

        auto comp = [&](int a, int b){
            return tasks[a][0] < tasks[b][0] ||
                (tasks[a][0] == tasks[b][0] && a < b);
        };

        sort(indices.begin(), indices.end(), comp);

        auto comp2 = [&](int a, int b){
            return tasks[a][1] > tasks[b][1] ||
                (tasks[a][1] == tasks[b][1] && a > b);
        };

        priority_queue<int, vector<int>, decltype(comp2)> minHeap(comp2);

        vector<int> res;
        int time = 0;
        int i = 0;
        
        while(!minHeap.empty() || i < n){
            while(i < n && tasks[indices[i]][0] <= time){
                minHeap.push(indices[i]);
                i++;
            }

            if(minHeap.empty()){
                time = tasks[indices[i]][0];
                continue;
            }

            int next = minHeap.top();
            minHeap.pop();
            time += tasks[next][1];
            res.push_back(next);
        }
            
        return res;
    }

};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [&](auto& a, auto& b){
            return a[1] < b[1];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        int available = capacity;

        for(auto& trip : trips){
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            while(!minHeap.empty() && minHeap.top().first <= from){
                available += minHeap.top().second;
                minHeap.pop();
            }

            if(numPassengers > available) return false;

            available -= numPassengers;
            minHeap.push({to, numPassengers});
        }
        
        return true;
    }
};
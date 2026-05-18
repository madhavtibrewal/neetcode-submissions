class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> fleet;

        for(int i = 0; i < n; i++){
            fleet.push_back({position[i], speed[i]});
        }

        sort(fleet.rbegin(), fleet.rend());

        double prevTime = (double)(target - fleet[0].first) / fleet[0].second;
        int count = n;

        for(int i = 1; i < n; i++){
            double current = (double)(target - fleet[i].first) / fleet[i].second;

            if(prevTime >= current){
                count--;
            }
            else{
                prevTime = current;
            }
        }

        return count;


    }
};

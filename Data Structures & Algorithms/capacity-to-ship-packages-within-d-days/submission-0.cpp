class Solution {
public:
    int calCap(vector<int>& weights, int cap, int days){
        int ships = 1;
        int curCap = cap;
        for(int w : weights){
            curCap -= w;
            if(curCap < 0){
                ships++;
                curCap = cap - w;
            }
        }
        return ships <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int cap = 0;
        int maxCap = INT_MIN;
        int res;
        for(int i : weights){
            cap += i;
            maxCap = max(maxCap, i);
        }

        int l = maxCap, r = cap;

        while(l <= r){
            int m = l  + (r - l) / 2;

            if(calCap(weights, m, days)){
                res = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return res;
    }
};
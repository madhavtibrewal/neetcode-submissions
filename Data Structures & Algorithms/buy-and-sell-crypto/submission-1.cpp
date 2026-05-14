class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int n = prices.size();
        int minL = prices[0];
        int ans = 0;

        for(int i = 1; i < n; i++){
            ans = max(ans, prices[i] - minL);
            minL = min(minL, prices[i]);
        }

        return ans;

    }
};

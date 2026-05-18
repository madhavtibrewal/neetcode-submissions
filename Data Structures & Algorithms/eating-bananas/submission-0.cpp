class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());

        int l = 1;

        int res = 0;

        while(l <= r){
            int k = l + ((r - l) / 2 );

            long long totalTime = 0;

            for(int p : piles){
                totalTime += ceil((double)p / k);
            }

            if(totalTime <= h){
                res = k;
                r = k - 1;
            }
            else{
                l = k + 1;
            }
        }        
        return res;
    }
};

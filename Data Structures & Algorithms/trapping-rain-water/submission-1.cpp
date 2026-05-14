class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int lMax = height[0], rMax = height[r];
        int ans = 0;

        while(l <= r){
            int curr = 0;
            if(lMax <= rMax){
                curr = lMax - height[l];
                if(curr > 0){
                    ans += curr;
                }
                lMax = max(lMax, height[l]);
                l++;
            }
            else{
                curr = rMax - height[r];
                if(curr > 0){
                    ans += curr;
                }
                rMax = max(rMax, height[r]);
                r--;
            }
        }

        return ans;
    }
};

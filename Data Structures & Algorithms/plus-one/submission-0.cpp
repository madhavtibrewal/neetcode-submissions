class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0;
        int n = digits.size();
        vector<int> ans(n);
        int carry  = 1;
        int i;
        for(i = n - 1; i >= 0; i--){
            int sig = carry + digits[i];
            carry = sig / 10 ;
            int remainder = sig % 10;

            ans[i] = remainder;
            cout << remainder <<" ";
        }

        if(carry != 0){
            ans.insert(ans.begin(), carry);
        }

        return ans;

        
    }
};

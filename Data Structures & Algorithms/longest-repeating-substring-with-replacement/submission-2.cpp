class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0, maxf = 0;
        int n = s.size();
        int ans = 0;

        for(int r = 0; r < s.size(); r++){
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            if((r - l + 1) - maxf > k){
                count[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

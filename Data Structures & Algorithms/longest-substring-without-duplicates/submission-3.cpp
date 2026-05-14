class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int l = 0, r = 0;
        int ans = 0;
        int n = s.size();

        while(l <= r && r < n){
            if(chars.find(s[r]) == chars.end()){
                chars.insert(s[r]);
                ans = max(ans, r - l + 1);
                r++;
            }
            else{
                chars.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};

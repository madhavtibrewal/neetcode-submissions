class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> countT, window;

        for(char c : t) countT[c]++;

        int have = 0, need = countT.size();
        string ans = "";
        int minLength = INT_MAX;

        pair<int, int> res = {-1, -1};

        int n = s.size();
        int l = 0, r = 0;

        while(r < n){

            window[s[r]]++;
            if(countT[s[r]] != 0 && window[s[r]] == countT[s[r]]) have++;

            while(have == need){
                if((r - l + 1) < minLength){
                    minLength = r - l + 1;
                    res = {l, minLength};
                }   

                window[s[l]]--;
                if(countT[s[l]] != 0 && window[s[l]] < countT[s[l]]) have--;
                l++;
            }
            r++;
        }

        return minLength == INT_MAX ? "" : s.substr(res.first, res.second);

    }
};

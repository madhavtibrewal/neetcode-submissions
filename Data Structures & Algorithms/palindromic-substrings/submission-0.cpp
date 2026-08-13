class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for(int i = 0; i <  s.size(); i++){
            res += calPali(i, i, s);
            res += calPali(i, i + 1, s);
        }

        return res;
    }

    int calPali(int l, int r, string s){
        int count = 0;
        while(l >= 0 && r <= s.size() && s[l] == s[r]){
            l--;
            r++;
            count++;
        }

        return count;
    }
};

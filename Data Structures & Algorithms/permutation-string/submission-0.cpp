class Solution {
public:
    bool isPerm(string s2, string s1){
        sort(s2.begin(), s2.end());
        sort(s1.begin(), s1.end());

        for(int i = 0; i < s2.size(); i++){
            if(s2[i] != s1[i]) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        /*unordered_map<int, int> freq;

        for(char c : s1){
            freq[c]++;
        }*/

        for(int i = 0; i <= n2 - n1; i++){
            if(isPerm(s2.substr(i, n1), s1)){
                return true;
            }
        }

        return false;
    }
};

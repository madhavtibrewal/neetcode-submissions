class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int n = word1.size();
        int m = word2.size();

        for(int i = 0; i < n || i < m; i++){
            if(i < n){
                res += word1[i];
            }
            if(i < m){
                res += word2[i];
            }
        }

        return res;
    }
};
class Solution {
public:
    bool isPerm(string s2, string s1){
        sort(s2.begin(), s2.end());

        for(int i = 0; i < s2.size(); i++){
            if(s2[i] != s1[i]) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        //sort(s1.begin(), s1.end());

        if(n1 > n2) return false;

        vector<int> counts1(26, 0);
        vector<int> counts2(26, 0);

        for(int i = 0; i < s1.size(); i++){
            counts1[s1[i] - 'a']++;
            counts2[s2[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(counts1[i] == counts2[i]){
                matches++;
            }
        }


        int l = 0, r = n1;

        while(r < n2){
            if(matches == 26) return true;
            int indexL = s2[l] - 'a';
            int indexR = s2[r] - 'a';
            
            counts2[indexR]++;

            if(counts2[indexR] == counts1[indexR]) matches++;
            else if(counts2[indexR] == counts1[indexR] + 1) matches--;
            
            counts2[indexL]--;

            if(counts2[indexL] == counts1[indexL]) matches++;
            else if(counts2[indexL] == counts1[indexL] - 1) matches--;
            
            l++;
            r++;
        }

        return matches == 26;
    }
};

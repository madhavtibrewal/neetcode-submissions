class Solution {
public:
    string removeDuplicates(string s, int k) {
        while(true){
            bool flag = false;

            int i = 0;
            int cnt = 1;

            for(int j = 1; j < s.size(); j++){
                if(s[j] == s[i]){
                    cnt++;
                }
                else{
                    cnt = 1;
                    i = j;
                }

                if(cnt == k){
                    s = s.substr(0, i) + s.substr(j + 1);
                    flag = true;
                    break;

                }
            }

            if(!flag){
                break;
            }
        }
        return s;
    }
};
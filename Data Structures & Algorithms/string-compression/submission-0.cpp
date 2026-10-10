class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int n = chars.size();
        int k = 0;

        while(i < n){
            chars[k++] = chars[i];
            int j = i + 1;

            while(j < n && chars[i] == chars[j]){
                j++;
            }

            if(j - i > 1){
                string l = to_string(j - i);
                for(char c : l){
                    chars[k++] = c;
                }
            }
            i = j;
        }

        return k;
    }
};
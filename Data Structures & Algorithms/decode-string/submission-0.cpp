class Solution {
public:
    string decodeString(string s) {
        vector<char> st;

        for(char c : s){
            if(c == ']'){
                string curr = "";
                while(!st.empty() && st.back() != '['){
                    curr += st.back();
                    st.pop_back();
                }
                reverse(curr.begin(), curr.end());
                st.pop_back();

                string num = "";
                while(!st.empty() && isdigit(st.back())){
                    num += st.back();
                    st.pop_back();
                }
                reverse(num.begin(), num.end());
                int k = stoi(num);

                while(k--){
                    for(char c : curr){
                        st.push_back(c);
                    }
                }
            }
            else{
                st.push_back(c);
            }
        }

        string res(st.begin(), st.end());

        return res;
    }
};
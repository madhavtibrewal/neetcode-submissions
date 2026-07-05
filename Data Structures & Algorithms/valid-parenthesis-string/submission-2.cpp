class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left_st;
        stack<int> star_st;
        int n = s.size();
        if(n == 0) return true;

        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                if(left_st.empty() && star_st.empty()) return false;
                if(!left_st.empty())
                    left_st.pop();
                else if(!star_st.empty())
                    star_st.pop();
            }
            else if(s[i] == '(')
                left_st.push(i);
            else
                star_st.push(i);
        }

        while(!left_st.empty() && !star_st.empty()){
            if(left_st.top() > star_st.top()) return false;
            left_st.pop();
            star_st.pop();
        }

        return left_st.empty();
    }
};

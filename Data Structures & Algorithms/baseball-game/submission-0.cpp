class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int res = 0;

        for(string op : operations){
            if(op == "+"){
                int top = st.top();
                st.pop();
                int newTop = top + st.top();
                st.push(top);
                st.push(newTop);
                res += newTop;
            }
            else if(op == "C"){
                res -= st.top();
                st.pop();
            }
            else if(op == "D"){
                int newTop = st.top() * 2;
                res += newTop;
                st.push(newTop);
            }
            else{
                st.push(stoi(op));
                res += st.top();
            }
        }
        return res;
    }
};
class Solution {
public:
    int operate(int first, int second, string operand){
        if(operand == "*") return first * second;
        else if(operand == "-") return first - second;
        else if(operand == "/") return first / second;
        else if(operand == "+") return first + second;

        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string s : tokens){
            if(st.empty()){
                st.push(s);
                continue;
            }

            if(s == "*" || s == "+" || s == "-" || s == "/"){
                int top2 = stoi(st.top());
                st.pop();
                int top1 = stoi(st.top());
                st.pop();
                st.push(to_string(operate(top1, top2, s)));
            }
            else{
                st.push(s);
            }
        }

        return stoi(st.top());
    }
};

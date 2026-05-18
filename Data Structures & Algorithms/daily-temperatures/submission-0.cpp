class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();

        st.push(0);

        for(int i = 1; i < n; i++){
            int index = st.top();
            if(temperatures[index] >= temperatures[i]){
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[index] < temperatures[i]){
                    temperatures[index] = i - index;
                    st.pop();
                    if(!st.empty()) index = st.top();
                }
                st.push(i);
            }
        }

        while(!st.empty()){
            int index = st.top();
            temperatures[index] = 0;
            st.pop();
        }

        return temperatures;
    }
};

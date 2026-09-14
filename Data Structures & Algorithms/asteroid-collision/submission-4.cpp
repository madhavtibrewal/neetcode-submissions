class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int i : asteroids){
            bool destroyed = false;
            if(i > 0) {
                st.push_back(i);
                continue;
            }
            while(!st.empty() && st.back() > 0){
                if(st.back() > abs(i)){
                    destroyed = true;
                    break;
                }
                else if(st.back() == abs(i)){
                    destroyed = true;
                    st.pop_back();
                    break;
                }
                else{
                    st.pop_back();
                }
            }

            if(!destroyed){
                st.push_back(i);
            }
            
        }

        return st;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int n = num2.size();
        int m = num1.size();
        vector<int> res(n + m, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                res[i + j + 1] += (num2[i] - '0') * (num1[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] = res[i + j + 1] % 10;
            }
        }

        string result = "";
        int start = (res[0] == 0) ? 1 : 0;

        while(start < res.size()){
            result += to_string(res[start]);
            start++;
        }
        //int i = res.size() - 1;

        //while()

        return result;
        
    }
};

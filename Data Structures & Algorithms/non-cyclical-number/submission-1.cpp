class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
            
            if(n == 0){
                if(s.contains(sum)) return false;
                if(sum == 1) return true;
                s.insert(sum);
                n = sum;
                sum = 0;
            }
        }
        return false;
    }
};

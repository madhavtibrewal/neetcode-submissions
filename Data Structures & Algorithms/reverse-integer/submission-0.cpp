class Solution {
public:
    int reverse(int x) {
        const int MAX = 2147483647, MIN = -2147483648;
        int res = 0;
        int num = x;

        while(num != 0){
            int digit = num % 10;
            if(res > MAX / 10 || (res == MAX / 10 && digit > 7)){
                return 0;
            }
            if(res < MIN / 10 || (res == MIN / 10 && digit < -8)){
                return 0;
            }
            res = res * 10 + digit;
            num = num / 10;
        }

        return res;
    }
};

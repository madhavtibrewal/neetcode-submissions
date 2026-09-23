class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber > 0){
            columnNumber--;
            int ascii = columnNumber % 26;
            char c = 'A' + ascii;
            s = c + s;
            columnNumber /= 26;
        }

        return s;
    }
};
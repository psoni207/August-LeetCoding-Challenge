class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        
        for(char ch : s){
            int num = ch - 'A' + 1;
            result = result*26 + num;
        }
        return result;
    }
};
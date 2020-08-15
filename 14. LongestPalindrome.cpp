class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(60, 0);
        for(char c: s){
            freq[c-'A'] += 1;
        }
        
        int countOdds = 0;
        int res = 0;
        
        for(int i = 0; i < 60; i++){
            if(freq[i]%2){
                countOdds += 1;
            }
            res += freq[i];
        }
        
        if(countOdds != 0)
            res -= (countOdds-1);
        return res;
        
    }
};
class Solution {
public:
    bool detectCapitalUse(string word) {
        
        char C1 = 'A', C2 = 'Z';
        char S1 = 'a', S2 = 'z';
        
        if(C1 <= word[0] && word[0] <= C2){
            return (helperCheck(word, C1, C2) || helperCheck(word, S1, S2) );
        }
        return helperCheck(word, S1, S2);
    }
    
    bool helperCheck(string &word, char L1, char L2){
        
        for(int i = 1; i < word.size(); i += 1){
            if(word[i] < L1 || word[i] > L2){
                return false;
            }    
        }   
        
        return true;
    }
};
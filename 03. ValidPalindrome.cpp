class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        
        int i = 0;
        while(i < s.size()){
            if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ){
                str += s[i];
            }else if( s[i] >= 'A' && s[i] <= 'Z' ){
                str += (char)((int)s[i] + 32);
            }
            i += 1;
        }
        
        int start = 0;
        int end = str.size()-1;
        
        while(start < end){
            if(str[start++] != str[end--]){
                return false;
            }
        }
        
        return true;
    }
};
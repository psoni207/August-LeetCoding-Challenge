class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> uset;
        uset.insert({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        
        int n = S.size();
        string res = "";
        string temp = "";
        string  As = "a";
        for(int i = 0; i < n; i++){
            if(S[i] == ' '){
                if(uset.find(temp[0]) != uset.end()){
                    res += temp + "ma" + As + " ";
                }else{
                    if(temp.size() > 1){
                        res += temp.substr(1) + temp[0] + "ma" + As + " ";   
                    }else{
                        res += temp + "ma" + As + " ";
                    }
                }
                As += 'a';
                temp = "";
            }else{
                temp += S[i];
            }
        }
        
        if(temp.size() > 0){
            if(uset.find(temp[0]) != uset.end()){
                    res += temp + "ma" + As;
            }else{
                if(temp.size() > 1){
                    res += temp.substr(1) + temp[0] + "ma" + As;   
                }else{
                    res += temp + "ma" + As;
                }
            }
        }
        
        return res;
    }
};
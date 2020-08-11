class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0){
            return 0;
        }
        sort(citations.begin(), citations.end() );
 
        int result = 0;
        for(int i = n-1; i >= 0; i--){
            int cnt = n-i;
            if(citations[i] >= cnt){
                result = cnt;
            }else{
                break;
            }
        }

        return result;
        
    }
};
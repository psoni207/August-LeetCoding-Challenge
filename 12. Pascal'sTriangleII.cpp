class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        
        if(rowIndex == 0){
            return res;
        }
        
        
        for(int  i = 1; i <= rowIndex; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1; j < res.size(); j++){
                temp.push_back(res[j]+res[j-1]);
            }
            temp.push_back(1);
            
            res.swap(temp);
        }
        
        return res;
    }
};
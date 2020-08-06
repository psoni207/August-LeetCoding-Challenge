class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dup(n,0);
        
        vector<int> res;
        for(int num: nums){
            if(dup[num-1] == 1){
                res.push_back(num);
            }else{
                dup[num-1] = 1;
            }
        }
        
        return res;
    }
};
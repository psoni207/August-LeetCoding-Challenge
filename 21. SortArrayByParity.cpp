class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int low = 0;
        int high = n-1;
        
        while(low < high){
            if(A[low]%2 == 0){
                low += 1;
            }else{
                swap(A[low], A[high]);
                high -= 1;
            }
        }
        
        return A;
    }
};
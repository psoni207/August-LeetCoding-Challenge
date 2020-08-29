class Solution {
    void flip(vector<int>& A, int idx){
        for(int i = 0; i <= idx/2; ++i){
            int tmp = A[i];
            A[i] = A[idx-i];
            A[idx-i] = tmp;
        }
    }
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        int N = A.size();
        
        bool flag = false;
        for(int i = N; i > 1; i -= 1){
            for(int j = 1; j < i; j += 1){
                
                if(A[j] == i && j+1 == i){
                    flag = true;
                    break;
                }
                if(A[j] == i){
                    flip(A, j);
                    result.push_back(j+1);
                    break;
                }
            }
            if(!flag){
                flip(A, i-1);
                result.push_back(i);                
            }
            flag = false;

        }
        return result;
    }
};
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0){
            return false;
            
        }
        
        if(ceil(log(num)/log(4)) == floor(log(num)/log(4))){
            return true;
        }
        
        return false;
        
        /*
        if( !(num & (num-1)) ){
            int count = 0;
            while(num > 1){
                count += 1;
                num >= 1;
            }
            
            if(count%2 == 0){
                return true;
            }
        }
        
        return false;
        
        */
    }
    
};
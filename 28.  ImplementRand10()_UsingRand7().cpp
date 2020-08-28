// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a, b;
        
        while(1){
            a = rand7();
            b = rand7();
            
            a = (a-1)*7 + b;
            if(a <= 40){
                return (a%10 + 1);
            }
        }
        
    }
};
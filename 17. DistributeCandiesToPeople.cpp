class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int idx = 0, candies_count = 1;
        while(candies){
            result[idx++] += candies_count;
            candies -= candies_count++;
            if(idx == num_people) idx = 0;
            if(candies_count > candies) candies_count = candies;
        }
        return result;
    }
};
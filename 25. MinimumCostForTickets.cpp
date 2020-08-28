
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1);
        
        dp[0] = 0;
        
        int week = 0;
        int month = 0;
        
        for(int i = 0; i < n; i++) { 
            while(days[week] <= days[i]-7) {
                week++;
            } 
            while(days[month] <= days[i]-30) {
                month++;
            }
            dp[i+1] = min({costs[0] + dp[i], costs[1] + dp[week], costs[2] + dp[month]});           
        }
        
        return dp[n];   
    }
};


/*
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 365*costs[0]);// Max Value, worst scenario
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i -= 1){
            int week = i;
            int month = i;
            while(week < n && days[week] < days[i] + 7){
                week += 1;
            } //Clubbing the ticket with a weekly ticket
            while(month < n && days[month] < days[i] + 30){
                month += 1;
            } //Clubbing the ticket with a monthly ticket
            dp[i] = min({costs[0] + dp[i+1], costs[1] + dp[week], costs[2] + dp[month]});
        }
        return dp[0];
    }
};
*/

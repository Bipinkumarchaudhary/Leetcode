class Solution {
public:
    int solve(int i,int j,int& m,int& n,string s1,string s2,vector<vector<int>> &dp){
        if(i==m){
            return n-j;
        }
        if(j==n){
            return m-i;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j] = solve(i+1,j+1,m,n,s1,s2,dp);
        }else{
            // #deletion
            // #insertion
            // #replace
            return dp[i][j] = min({solve(i+1,j,m,n,s1,s2,dp)+1,solve(i,j+1,m,n,s1,s2,dp)+1,solve(i+1,j+1,m,n,s1,s2,dp)+1});
        }
    }
    int minDistance(string s1, string s2) {
        int m = s1.length(),n=s2.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,s1,s2,dp);
    }
};
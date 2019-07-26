#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int solve(vector<vector<int>> &dp,int n,int m){
    if((dp[0][0]==-1)||(dp[n-1][m-1]==-1)){
        return 0;
    }
    for(int i=0;i<n;++i){
        if(dp[i][0]==-1) break;
        else dp[i][0]=1;
    }
    for(int j=0;j<m;++j){
        if(dp[0][j]==-1) break;
        else dp[0][j]=1;
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            dp[i][j] = 0;
            if(dp[i][j]!=-1){
                if(dp[i-1][j]!=-1) dp[i][j] = dp[i-1][j];
                if(dp[i][j-1]!=-1) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,q,i,j;
    cin>>n>>m>>q;
    vector<vector<int>> dp(n,vector<int>(m,0));
    while(q--){
        cin>>i>>j;
        dp[i-1][j-1] = -1;
    }
    cout<<solve(dp,n,m);
    return 0;
}

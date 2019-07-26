#include<bits/stdc++.h>
using namespace std;
#define ll long long
int find_sum(vector<int> &csum,int i,int j){
    int sum = csum[j];
    if(i>0) sum -= csum[i-1];
    return (sum+100)%100;
}
ll solve(vector<int> A){
    int n = A.size();
    for(int i=1;i<n;++i){ // finding cumulative sum
        A[i] = (A[i]+A[i-1])%100;
    }
    vector<vector<ll>> dp(n,vector<ll>(n,INT_MAX));
    // smoke produces when no mixtures is 0
    for(int i=0;i<n;++i) dp[i][i] = 0;
    for(int l=2;l<=n;++l){
        for(int i=0;i<=(n-l);++i){
            int j = i+l-1;
            for(int k=i;k<j;++k){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+find_sum(A,i,k)*find_sum(A,k+1,j));
            }
        }
    }
    /*
    for(auto x:dp){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    */
    return dp[0][n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(cin>>n){
        vector<int> A(n);
        for(int i=0;i<n;++i) cin>>A[i];
        //for(auto x:A) cout<<x<<" ";
        cout<<solve(A)<<"\n";
    }
    return 0;
}

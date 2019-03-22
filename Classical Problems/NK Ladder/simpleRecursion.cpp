//problem
/*
Given a ladder of N steps.
You can climb 1 to K number of steps in one jumps. Find number of ways to reach the Nth step from the ground(N=0)
Input
N K
Output
Number of ways to reach the Nth step.
There is only 1 way to stand on the ground i.e for N=0 number of ways = 1
*/
//O(k^n)
#include<bits/stdc++.h>
using namespace std;
int solve(int n,int k){
    if(n<-1) return 0;
    if(n==0) return 1;
    int cnt = 0;
    for(int i=1;i<=k;++i){
        cnt += solve(n-i,k);
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
    return 0;
}


//Given a brick wall of 4xN and tiles of shape 1x4 . Compute total number of ways to arrange tiles on the wall.
#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    //Base case
    if(n<=0) return 0;
    if(n==1) return 1;
    if(n==4) return 2;
    //Recursive Case
    return solve(n-1)  + solve(n-4);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    while(cin>>n) cout<<solve(n)<<"\n";
    return 0;
}
//This recurrence can also be solved using matrix exponentiation

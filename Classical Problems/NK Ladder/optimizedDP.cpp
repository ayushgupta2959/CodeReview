#include<bits/stdc++.h>
using namespace std;
//Recursive equation
//f(n) = 2f(n-1) - f(n-k-1);
//O(k^2 + (n-k))
int solve(int n,int k){
    int arr[n+1] = {0};
    arr[0] = 1;
    int c;
    int i;
    for(i=1;i<=k;++i){
        c = 0;
        for(int j = 1;j<=k;++j){
            if((i-j)>=0) c+= arr[i-j];
        }
        arr[i] = c;
    }
    for(;i<=n;++i){
        arr[i] = 2*arr[i-1] - arr[n-k-1];
    }
    return arr[n];
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

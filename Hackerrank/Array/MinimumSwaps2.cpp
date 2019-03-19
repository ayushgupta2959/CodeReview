#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,i,swps;
    cin>>n;
    int arr[n+1];
    for(i=1;i<=n;i++) cin>>arr[i];
    i=1;swps=0;
    while(i<=n || arr[n]!=n){
        while(arr[i]<i) {arr[i] = arr[arr[i]]; swps++;}
        i++;
    }
    cout<<swps;
    return 0;
}

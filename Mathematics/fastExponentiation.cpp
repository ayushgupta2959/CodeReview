#include<bits/stdc++.h>
using namespace std;
int power(int a,int n){
    if(n==0) return 1;
    int ans = power(a,n>>1);
    ans *= ans;
    if(n&1) ans *= a;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<< power(2,10)<<"\n";
    cout<<power(3,10)<<"\n";
    return 0;
}

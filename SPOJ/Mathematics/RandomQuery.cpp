#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll A[1000006],L[1000006] = {0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll c,n,s;
    double r;
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>A[i];
    s = 0;
    c = 0;
    for(ll i=1;i<=n;++i){
        c = c + (i - L[A[i]]);
        L[A[i]] = i;
        s += c;
    }
    r = (2*s - n)/(n*n*1.0);
    cout<<fixed<<setprecision(6)<<r;
    return 0;
}

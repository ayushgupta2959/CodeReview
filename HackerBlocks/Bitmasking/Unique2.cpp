#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int xor_all = 0;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    for(int i=0;i<n;++i) xor_all = xor_all^v[i];
    int mask = xor_all^(xor_all&(xor_all-1));
    int fu = 0; int su = 0;
    for(int i=0;i<n;++i) if(v[i]&mask) fu = fu^v[i];
    su = xor_all^fu;
    cout<<fu<<" "<<su;
    return 0;
}

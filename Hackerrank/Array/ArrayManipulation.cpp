#include<bits/stdc++.h>
using namespace std;
//Using Difference Array
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long n,m,a,b,k,mx,t;
    cin>>n>>m;
    // declaring long long D[n+2] will not work declare in this way
    long long *D=new long long[n+2]();
    while(m--){
        cin>>a>>b>>k;
        D[a] += k;
        D[b+1] -= k;
    }
    mx = t = D[1];
    for(int i=2;i<=n;++i){
        t += D[i];
        if(t>mx) mx = t;
    }
    cout<<mx<<"\n";
    return 0;
}

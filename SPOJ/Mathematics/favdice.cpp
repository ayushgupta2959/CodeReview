#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t,n;
    cin>>t;
    double hn[1001]; //harmonic number
    double ts=0;
    for(int i=1;i<1001;++i){
        ts += 1.0/((double)i);
        hn[i] = ts;
    }
    while(t--){
        cin>>n;
        cout<<fixed<<setprecision(2)<<n*hn[n]<<"\n";
    }
    return 0;
}

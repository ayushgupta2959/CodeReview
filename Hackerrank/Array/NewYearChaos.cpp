#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t,n,swps,x;
    bool flag;
    vector<int> v(100001);
    cin>>t;
    while(t--){
        cin>>n;
        swps = 0;
        //Method 1

        for(int i=0;i<n;++i) cin>>v[i];
        for(int i=n-1;i>=0;--i){
            if((v[i]-i-1)>2) {cout<<"Too chaotic\n";swps = 0;break;}
            for(int j=max(0,v[i]-2);j<i;++j) if(v[j]>v[i]) swps++;
        }
        if(swps) cout<<swps<<"\n";
    }
    return 0;
}

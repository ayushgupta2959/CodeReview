#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t,n,swps;
    bool flag;
    vector<int> v(100001);
    cin>>t;
    while(t--){
        cin>>n;
        swps = 0;
        for(int i=0;i<n;++i) cin>>v[i];
        //Method 1
        /*
        for(int i=n-1;i>=0;--i){
            if((v[i]-i-1)>2) {cout<<"Too chaotic\n";swps = 0;break;}
            for(int j=max(0,v[i]-2);j<i;++j) if(v[j]>v[i]) swps++;
        }
        if(swps) cout<<swps<<"\n";
        */
        //Method 2
        int fx = 1;int sx = 2;int tx = 3;
        for(int i=0;i<n;++i){if(v[i] == fx){
                fx = sx;
                sx = tx;
                tx++;
            }
            else if(v[i] == sx){
                sx = tx;
                tx++;
                swps++;
            }
            else if(v[i] == tx){
                swps+=2;
                tx++;
            }
            else{
                cout<<"Too chaotic\n";
                swps = 0;
                break;
            }
        }
        if(swps) cout<<swps<<"\n";
    }
    return 0;
}

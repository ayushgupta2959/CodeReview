#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,d;
    cin>>n>>d;
    vector<int> v(2*n);
    for(int i=0;i<n;++i) cin>>v[i];
    //Method 1
    copy(v.begin(),v.begin()+d,v.begin()+n);
    for(int i=0;i<n;++i){
        if(i) cout<<" ";
        cout<<v[i+d];
    }
    //Method 2
    /*
    for(int i=0;i<n;++i){
        if(i) cout<<" ";
        cout<<v[(i+d)%n];
    }
    */
    return 0;
}

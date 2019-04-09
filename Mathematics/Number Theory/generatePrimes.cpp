#include<bits/stdc++.h>
using namespace std;
//O(N log log N)
void primeSieve(bool *p,int n){
    p[2] = true;
    for(int i=3;i<=n;i+=2) p[i] = true;
    for(int i=3;i<=n;i+=2){
        if(p[i]){
            for(int j=i*i;j<=n;j+=2*i){
                p[j] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool p[n+1] = {false};
    primeSieve(p,n);
    for(int i=0;i<=n;++i){
        if(p[i]) cout<<i<<" ";
    }
    return 0;
}

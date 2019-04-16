#include<bits/stdc++.h>
using namespace std;
//Pigeonhole Principle
#define ull unsigned long long
ull A[100001];
int N;
void solve(){
    if(N>=130) {
        cout<<"Yes\n";
        return;
    }

    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            for(int k=j+1;k<N;++k){
                for(int l=k+1;l<N;++l){
                    if((A[i]^A[j]^A[k]^A[l])==0){
                        cout<<"Yes\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"No\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>N;
    for(int i=0;i<N;++i) cin>>A[i];
    solve();
    return 0;
}

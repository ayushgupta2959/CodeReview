#include<bits/stdc++.h>
using namespace std;
//Using Matrix Exponentiation and Matrix method to solve recursion
#define MOD 1000000000
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>

ll N,K;
vll B(12),C(12);
vvll T(12,vll(12));

vvll multiply(vvll a,vvll b){
    vvll res(K,vll(K));
    for(int m =0;m<K;++m){
        for(int n=0;n<K;++n){
            for(int o = 0;o<K;o++){
                res[m][n] = (res[m][n] + (a[m][o]*b[o][n])%MOD)%MOD;
            }
        }
    }
    return res;
}
vvll power(vvll t,ll tn){
    if(tn == 1) return t;
    vvll r = power(t,tn>>1);
    r = multiply(r,r);
    if(tn&1) r = multiply(r,t);
    return r;
}
ll solve(){
    if(N<K) return B[N-1];
    for(int i=0;i<(K-1);++i){
        for(int j=0;j<K;++j){
            if(j == i+1) T[i][i+1] = 1;
            else         T[i][j] = 0;
        }
    }
    for(int i=0;i<K;++i){
        T[K-1][i] = C[K-i-1];
    }
    T = power(T,N-1);
    ll ans = 0;
    for(int i=0;i<K;++i){
        ans = (ans + (T[0][i]*B[i])%MOD)%MOD;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int tc;
    cin>>tc;
    while(tc--){
        cin>>K;
        for(int i=0;i<K;++i) cin>>B[i];
        for(int i=0;i<K;++i) cin>>C[i];
        cin>>N;
        cout<<solve()<<"\n";
    }
    return 0;
}

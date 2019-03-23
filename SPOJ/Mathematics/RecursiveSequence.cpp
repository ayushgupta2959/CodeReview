#include<bits/stdc++.h>
using namespace std;
//Using Matrix Exponentiation and Matrix method to solve recursion
#define MOD 1000000000
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>

ll N,K;
vll B(10),C(10);
//Avoid creating large memory global
//Example : if create T global then program shows segmentation fault
vvll multiply(vvll a,vvll b){
    vvll res(K,vll(K));
    for(int m =0;m<K;++m){
        for(int n=0;n<K;++n){
            res[m][n] = 0;
            for(int o = 0;o<K;++o){
                res[m][n] = (res[m][n] + (a[m][o]*b[o][n])%MOD)%MOD;
            }
        }
    }
    return res;
}
vvll power(vvll t,ll tn){
    if(tn == 1) return t;
    vvll x = power(t,tn>>1);
    x = multiply(x,x);
    if(tn&1) x = multiply(x,t);
    return x;
}
ll solve(){
    vvll T(K,vll(K));
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin>>tc;
    while(tc--){
        cin>>K;
        for(int i=0;i<K;++i) cin>>B[i];
        for(int i=0;i<K;++i) cin>>C[i];
        cin>>N;
        cout<<solve()<<"\n";
        B.clear();
        C.clear();
    }
    return 0;
}

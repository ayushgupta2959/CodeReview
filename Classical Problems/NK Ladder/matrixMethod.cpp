#include<bits/stdc++.h>
using namespace std;
//Using Matrix Method for solving recurrence
//O((k^3)*log2(n))
vector<vector<int>> multiply(vector<vector<int>> a,vector<vector<int>> b,int k){
    vector<vector<int>> r(k,vector<int>(k));
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            r[i][j] = 0;
            for(int x = 0;x<k;++x){
                r[i][j] += (a[i][x] * b[x][j]);
            }
        }
    }
    return r;
}
vector<vector<int>> power(vector<vector<int>> t,int tn,int k){
    if(tn==1) return t;
    vector<vector<int>> r = power(t,tn>>1,k);
    r = multiply(r,r,k);
    if(tn&1) r = multiply(r,t,k);
    return r;
}
int solve(int n,int k){
    /*int f1[k] = {0};
    f1[k-1] = 1;
    */
    vector<vector<int>>t(k,vector<int>(k));
    for(int i=0;i<(k-1);++i){
        for(int j=0;j<k;++j){
            if(j== i+1) t[i][i+1] = 1;
            else        t[i][j] = 0;
        }
    }
    for(int i=0;i<k;++i){
        t[k-1][i] = 1;
    }
    t = power(t,n,k);
    return t[k-1][k-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool sortbyfirst(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first<b.first) return true;
    else if(a.first==b.first) return a.second<b.second;
    else return false;
}
bool sortbysecond(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second<b.second) return true;
    else if(a.second==b.second) return a.first<b.first;
    else return false;
}

ll dojobfirst(vector<pair<int,int>>p,ll n){
    ll c=0;
    pair<int,int> prev = {-1,-1};
    for(auto x:p){
        if((prev.first==x.first)&&(x.second==(prev.second+1)))
            c++;
        prev = x;
    }
    return c;
}
ll dojobsecond(vector<pair<int,int>>p,ll n){
    ll c=0;
    pair<int,int> prev = p[0];
    for(auto x:p){
        if((prev.second==x.second)&&(x.first==(prev.first+1)))
            c++;
        prev = x;
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    ll n,m,k,x,y,res,sres;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        res = 4*k;
        vector<pair<int,int>> p(k);
        for(ll i=0;i<k;++i){
            cin>>x>>y;
            p[i] = {x,y};
        }
        sort(p.begin(),p.end(),sortbyfirst);
        res -= 2*dojobfirst(p,k);
        sort(p.begin(),p.end(),sortbysecond);
        res -= 2*dojobsecond(p,k);
        cout<<res<<"\n";
    }
    return 0;
}

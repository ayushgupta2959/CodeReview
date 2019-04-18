#include<bits/stdc++.h>
using namespace std;
#define ll long long
//O(2^(N/2)log(N/2))
ll N,n1,n2,a,b;
vector<ll> subsum(ll *s,int n){
    ll tsn = (1<<n);
    vector<ll> ans;
    int j;
    ll t,sm;
    //Generating subsets using bit masking
    for(ll i=0;i<tsn;++i){
        j=0;
        sm = 0;
        t = i;
        while(t){
           if(t&1) sm += s[j];
           j++;
           t>>=1;
        }
        ans.emplace_back(sm);
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
    cin>>N>>a>>b;
    n1 = N>>1;
    n2 = N-n1;
    ll sn1[n1];
    ll sn2[n2];
    ll ts1,ts2,l,u,res=0;
    for(int i=0;i<n1;++i) cin>>sn1[i];
    for(int i=0;i<n2;++i) cin>>sn2[i];
    vector<ll> s1 = subsum(sn1,n1);
    vector<ll> s2 = subsum(sn2,n2);
    sort(s2.begin(),s2.end());
    ts1 = s1.size();
    ts2 = s2.size();
    for(ll i=0;i<ts1;++i){
        l = a - s1[i];
        u = b - s1[i];
        auto x1 = lower_bound(s2.begin(),s2.end(),l);
        auto x2 = upper_bound(s2.begin(),s2.end(),u);
        res  += (x2-s2.begin()) - (x1-s2.begin()); //since upper_bound returns the value that is just greater than u
                                                   // that is why no need to add one in res
    }
    cout<<res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define test cerr<<"abcd\n";

#define ll long long

ll fast_pow(ll a, int n){
    ll result = 1;
    for(int i = 0; i < n; ++i){
        result *= a;
    }
    return result;
}

int main() {
    sp;
    int t, n, verdict;
    ll x, s, sum;
    cin>>t;
    while(t--){
        cin>>n>>x;
        sum = fast_pow(10, n);
        s = 2*sum + x;
        cout<<s<<'\n'<<flush;
        cin>>x;
        cout<<(sum - x)<<'\n'<<flush;
        cin>>x;
        cout<<(sum - x)<<'\n'<<flush;
        cin>>verdict;
        if(verdict == -1) return 0;
    }
    return 0;
}


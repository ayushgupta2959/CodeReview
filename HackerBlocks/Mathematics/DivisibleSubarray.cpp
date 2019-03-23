#include<bits/stdc++.h>
using namespace std;
#define ll long long
//A : stores array elements
//F : F[i] stores frequency of (prefix_sum(1,i)%N) i.e. frequency of number 0 to N-1
//N : stores number of elements
ll A[100005],N,F[100005];
ll solve(){
    memset(F,0, sizeof F);
    F[0] = 1;//for null sub array
    ll sum=0;
    for(int i=1;i<=N;++i){
        sum+=A[i];
        F[sum%N]++;
    }
    sum=0;
    //Finding all combinations of sub arrays
    for(int i=0;i<N;++i){
        sum+=((F[i]*(F[i]-1))/2);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin>>tc;
    while(tc--){
        cin>>N;
        for(int i=1;i<=N;++i) cin>>A[i];
        cout<<solve()<<"\n";
    }
    return 0;
}

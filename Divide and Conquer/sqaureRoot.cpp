#include<bits/stdc++.h>
using namespace std;
double squareRoot(int n,int p){
    int l=0,h=n,mid,midsq;
    double ans;
    while(l<=h){
        mid=(l+h)/2;
        midsq = mid*mid;
        if(midsq==n){
            ans = mid;
            break;
        }
        else if(midsq<n){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    double inc = 0.1;
    for(int i=0;i<p;++i){
        while(ans*ans<n) ans+=inc;
        ans-=inc;
        inc/=10;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,p;
    while(cin>>n>>p){
        cout<<fixed<<setprecision(p)<<squareRoot(n,p)<<"\n";
    }
    return 0;
}

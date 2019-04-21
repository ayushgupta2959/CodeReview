#include<bits/stdc++.h>
using namespace std;
int multiply(int a,int b){
    if(b==0) return 0;
    int x = multiply(a,b>>1);
    x += x;
    if(b&1) x+=a;
    return x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b;
    while(cin>>a>>b) cout<<multiply(a,b)<<"\n";
    return 0;
}

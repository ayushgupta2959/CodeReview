#include<bits/stdc++.h>
using namespace std;
long long stringToInt(string s,int l){
    if(l==0) return 0;
    return stringToInt(s,l-1)*10  + (s[l-1]-'0');
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    while(cin>>s) cout<<stringToInt(s,s.length())<<"\n";
    return 0;
}

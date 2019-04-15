#include<bits/stdc++.h>
using namespace std;int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    while(getline(cin,s)){
    int n = s.length();
    int index = (1<<n) - 2;//finding count of lucky numbers with length less then n
    int t = 0;
    for(int i=0;i<n;++i){
        if(s[i]=='4') t = t<<1;
        else t = (t<<1) + 1;
    }
    t+=1;//since 1 based indexing
    index += t;
    cout<<index<<"\n";
    }
    return 0;
}

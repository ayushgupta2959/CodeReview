#include<bits/stdc++.h>
using namespace std;
bool subset_found(vector<int> notes,int n,int m,int i){
    int sum=0;
    int j=0;
    while(i>0){
        if(i&1) sum+=notes[j];
        i>>=1;
        j++;
    }
    if(sum==m) return true;
    else return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t,n,m,flag;
    cin>>t;
    while(t--){
        cin>>n>>m;
        flag=0;
        vector<int> notes(n);
        for(int i=0;i<n;++i)cin>>notes[i];
        int nsubs = (1<<n);
        for(int i=0;i<nsubs;++i){
            if(subset_found(notes,n,m,i)){
                flag=1;
                break;
            }
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}

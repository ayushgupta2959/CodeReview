#include<bits/stdc++.h>
using namespace std;
int binarySearch(int *a,int l,int r,int key){
    if(l>r) return -1;
    int m = (l+r)/2;
    if(a[m]==key) return m;
    else if(a[m]>key) return binarySearch(a,l,m-1,key);
    else return binarySearch(a,m+1,r,key);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,key;
    while(cin>>n){
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        cin>>key;
        cout<<binarySearch(a,0,n-1,key);
    }
    return 0;
}

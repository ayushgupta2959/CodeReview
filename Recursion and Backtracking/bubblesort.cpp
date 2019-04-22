#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int *a,int i,int n){
    if(n==1) return;
    if(i==n-1) return bubbleSort(a,0,n-1);
    if(a[i]>a[i+1]) swap(a[i],a[i+1]);
    bubbleSort(a,i+1,n);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    while(cin>>n){
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        bubbleSort(a,0,n);
        for(int i=0;i<n;++i) cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

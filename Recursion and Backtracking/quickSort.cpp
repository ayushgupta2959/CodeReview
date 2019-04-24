#include<bits/stdc++.h>
using namespace std;
int partition(int a,int l,int h){
    int p = a[l];
    int i = l+1;
    int j=l+2;


}
void quickSort(int *a,int l,int h){
    if(l>=h) return;
    int p = partition(a,l,h);
    quickSort(a,l,p-1);
    quickSort(a,p+1,l);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    quickSort(a,0,n-1);
    for(int i=0;i<n;++i) cout<<a[i]<<" ";
    return 0;
}

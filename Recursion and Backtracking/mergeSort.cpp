#include<bits/stdc++.h>
using namespace std;
void mergeArray(int *a,int l,int m,int h){
    int t[h-l+1];
    int i=l,j=m+1,k=0;
    while(i<=m && j<=h){
        if(a[i]<a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }
    while(i<=m)
        t[k++] = a[i++];
    while(j<=h)
        t[k++] = a[j++];
    k=0;
    for(i=l;i<=h;++i) a[i] = t[k++];
}
void mergeSort(int *a,int l,int h){
    if(l>=h) return;
    int m = (l+h)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,h);
    mergeArray(a,l,m,h);
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
    mergeSort(a,0,n-1);
    for(int i=0;i<n;++i) cout<<a[i]<<" ";
    return 0;
}

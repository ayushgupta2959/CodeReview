#include<bits/stdc++.h>
using namespace std;
int firstOccurence(int *a,int n,int key){
    int l = 0,h = n-1,ans = -1,mid;
    while(l<=h){
        mid = (l+h)/2;
        if(a[mid]==key){
            h=mid-1;
            ans=mid;
        }
        else if(a[mid]<key){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return ans;
}
int lastOccurence(int *a,int n,int key){
    int l = 0,h = n-1,ans = -1,mid;
    while(l<=h){
        mid = (l+h)/2;
        if(a[mid]==key){
            l=mid+1;
            ans=mid;
        }
        else if(a[mid]<key){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    int key;
    while(cin>>key){
        cout<<"First Occurence : "<<firstOccurence(a,n,key)<<"\n";
        cout<<"Last Occurence : "<<lastOccurence(a,n,key)<<"\n";
    }
    return 0;
}

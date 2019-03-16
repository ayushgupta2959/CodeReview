#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    int arr[n];
    int cnt[64] = {0};
    int result = 0;
    for(int i=0;i<n;++i) cin>>arr[i];
    for(int i=0;i<n;i++){
        int j=0;
        while(arr[i]){
            cnt[j++] += arr[i]&1;
            arr[i]>>=1;
        }
    }
    int p=1;
    for(int j=0;j<64;j++){
        result += (cnt[j]%3)*p;
        p<<=1;
    }

    cout<<result;
    return 0;
}

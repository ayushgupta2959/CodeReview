#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int arr[6][6];
    int msum = -70;
    int rr,rc;
    int tsum = 0;
    for(int i = 0;i<6;++i)
        for(int j = 0;j<6;++j)
            cin>>arr[i][j];
    for(int i = 0;i<4;++i){
        for(int j = 0;j<4;++j){
            tsum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(tsum>msum) msum = tsum;
        }
    }
    cout<<msum;
    return 0;
}

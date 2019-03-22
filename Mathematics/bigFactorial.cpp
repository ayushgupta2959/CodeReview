#include<bits/stdc++.h>
using namespace std;
void multiply(int *a,int &tn,int num){
    int carry = 0;
    int p;
    for(int i=0;i<tn;++i){
        p = a[i]*num + carry;
        carry = p/10;
        a[i] = p%10;
    }
    while(carry){
        a[tn++] = carry%10;
        carry /= 10;
    }
}
void bigFactorial(int n){
    int arr[1000] = {0}; // max 1000 digit decimal number
    int tn = 1;
    arr[0] = 1;
    for(int i=2;i<=n;++i){
        multiply(arr,tn,i);
    }
    for(int i=tn-1;i>=0;--i) cout<<arr[i];
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    bigFactorial(5);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool checkPrime(int x){
    if(x==1) return false;
    else if(x==2) return true;
    else if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<checkPrime(10)<<"\n";
    cout<<checkPrime(17)<<"\n";
    cout<<checkPrime(91)<<"\n";
    return 0;
}

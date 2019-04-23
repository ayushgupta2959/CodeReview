#include<bits/stdc++.h>
using namespace std;
void towerofhanoi(int n,char src,char dest,char helper){
    if(n==0) return;
    //Move n-1 discs from src to helper
    towerofhanoi(n-1,src,helper,dest);
    //Move nth disc from src to dest
    cout<<"Move disc "<<n<<" from "<<src<<" to "<<dest<<"\n";
    //Move n-1 discs from helper to dest
    towerofhanoi(n-1,helper,dest,src);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    towerofhanoi(n,'A','C','B');
    return 0;
}

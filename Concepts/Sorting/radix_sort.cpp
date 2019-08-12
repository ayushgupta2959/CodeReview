#include<bits/stdc++.h>
using namespace std;
void radix_sort(vector<int> &A){
    int n =A.size();
    int t1 = 1;
    int t2 = 10;
    bool flag;
    while(true){
        vector<vector<int>> m(10,vector<int>());
        flag = true;
        for(int i=0;i<n;++i){
            if(A[i]/t1>0){
                flag=false;
            }
            m[(A[i]/t1)%t2].emplace_back(A[i]);
        }
        int i=0;
        if(flag) return;
        for(auto x:m){
            for(auto y:x){
                A[i++] = y;
            }
        }
        t1 = t1*10;
    }
}
int main(){
    //vector<int> A = {5,6,1,2};
    vector<int> A = {5,6,7,1,45,222,45,4,84,27,90,836,68,229};
    radix_sort(A);
    for(auto x:A)cout<<x<<" ";
    return 0;
}

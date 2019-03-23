#include<bits/stdc++.h>
using namespace std;
void update(int **arr,int r,int c){
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j)
            arr[i][j] = i+j;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r = 10;
    int c = 10;
    int **arr = new int*[r];
    for(int i=0;i<r;++i) arr[i] = new int[c];
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            arr[i][j] = 0;
        }
    }
    update(arr,r,c);
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

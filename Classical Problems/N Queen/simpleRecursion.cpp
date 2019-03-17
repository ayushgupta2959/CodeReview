#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
bool board[15][15]={false};
int N;
//This solution take O(N^2) time for each row
void print_board(){
    cout<<"\nconfig "<<cnt<<"\n";
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(board[i][j]) cout<<"Q ";
            else            cout<<". ";
        }
        cout<<"\n";
    }
    cout<<"--------\n";
}
bool can_place(int r,int c){
    // checking column
    for(int i=0;i<r;++i)
        if(board[i][c]) return false;
    //checking left diagonal
    for(int i=r-1,j = c-1;i>=0 && j>=0;--i,--j)
        if(board[i][j]) return false;
    for(int i=r-1,j = c+1;i>=0 && j<N;--i,++j)
        if(board[i][j]) return false;
    return true;
}
void solve(int r){
    if(r==N){
        cnt++;
        print_board();
        return;
    }
    for(int c = 0;c<N;++c){
        if(can_place(r,c)){
            board[r][c] = true;
            solve(r+1);
            board[r][c] = false;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    solve(0);
    return 0;
}

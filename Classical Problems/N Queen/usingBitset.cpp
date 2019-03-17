#include<bits/stdc++.h>
using namespace std;
//This solution take O(N) time for each row

int cnt = 0;
bool board[15][15] = {false};
int N;
// for N size board bitset would be of size 2*n
bitset<30> col,ld,rd;
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
void solve(int r){
    if(N==r) {cnt++;print_board();return;}
    for(int c=0;c<N;++c){
        if(!col[c] && !ld[r-c+N-1] && !rd[r+c]){
            board[r][c] = true;
            col[c] = ld[r-c+N-1] = rd[r+c] = 1;
            solve(r+1);
            col[c] = ld[r-c+N-1] = rd[r+c] = 0;
            board[r][c] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    solve(0);
    cout<<cnt;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
// This solution take O(k) time for each row where k = no. of safe positions to place queen in a row
int cnt = 0;
int N;
int DONE;
void solve(int rowMask,int ld,int rd){
    if(rowMask == DONE){cnt++;return;}
    int safe = DONE&(~(rowMask|ld|rd));
    while(safe){
        int p = safe&(-safe);
        safe -= p;
        solve(rowMask|p,(ld|p)<<1,(rd|p)>>1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    DONE = (1<<N) -1;
    solve(0,0,0);
    cout<<cnt;
    return 0;
}
//code to print board
//time might take some extra time so implementation is shown separately
/*#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int N;
int DONE;
bool board[15][15];
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
//p has only one bit set corresponding to the position of placing queen in the current row
int find_column(int p){
    int c = 0;
    while(p){
        c++;p>>=1;
    }
    return c-1;
}
void solve(int rowMask,int ld,int rd,int r){
    if(rowMask == DONE){cnt++;print_board();return;}
    int safe = DONE&(~(rowMask|ld|rd));
    while(safe){
        int p = safe&(-safe);
        safe -= p;
        int c = find_column(p);
        board[r][c] = true;
        solve(rowMask|p,(ld|p)<<1,(rd|p)>>1,r+1);
        board[r][c] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    DONE = (1<<N) -1;
    solve(0,0,0,0);
    cout<<cnt;
    return 0;
}
*/

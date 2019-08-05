#include<bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second
using namespace std;
int solve_helper(vector<pi> &e1,vector<pi> &e2,vector<int> &t,pi src,pi dest,vector<bool> &visited,int n){
    if(src.f==dest.f && src.s==dest.s) return 0;
    int result = abs(src.f-dest.f)+abs(src.s-dest.s);
    int ans;
    int q1;
    int q2;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            visited[i]=true;
            q1 = abs(src.f-e1[i].f) + abs(src.s-e1[i].s) + t[i];
            q1 += solve_helper(e1,e2,t,e2[i],dest,visited,n);
            q2 = abs(src.f-e2[i].f) + abs(src.s-e2[i].s) + t[i];
            q2 += solve_helper(e1,e2,t,e1[i],dest,visited,n);
            ans = min(q1,q2);
            result = min(result,ans);
            visited[i]=false;
        }
    }
    return result;
}
int solve(vector<pi> &e1,vector<pi> &e2,vector<int> &t,pi src,pi dest,int n){
    vector<bool> visited(n,false);
    if(src.f==dest.f && src.s==dest.s) return 0;
    int result = abs(src.f-dest.f)+abs(src.s-dest.s);
    int ans;
    int q1;
    int q2;
    for(int i=0;i<n;++i){
        visited[i]=true;
        q1 = abs(src.f-e1[i].f)+abs(src.s-e1[i].s) + t[i];
        q1 += solve_helper(e1,e2,t,e2[i],dest,visited,n);
        q2 = abs(src.f-e2[i].f)+abs(src.s-e2[i].s) + t[i];
        q2 += solve_helper(e1,e2,t,e1[i],dest,visited,n);
        ans = min(q1,q2);
        result = min(result,ans);
        visited[i]=false;
    }
    return result;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T,n;
    cin>>T;
    vector<pi> e1; //end one of pipe
    vector<pi> e2; //end two of pipe
    vector<int> t; // time to travel in pipe
    pi src;
    pi dest;
    pi temp;
    int temp2;
    for(int i=1;i<=T;++i){
        cin>>n;
        e1.clear();
        e2.clear();
        t.clear();
        cin>>src.f>>src.s>>dest.f>>dest.s;
        for(int j=0;j<n;++j){
            cin>>temp.f>>temp.s;
            e1.emplace_back(temp);
            cin>>temp.f>>temp.s;
            e2.emplace_back(temp);
            cin>>temp2;
            t.emplace_back(temp2);
        }
        cout<<"#"<<i<<" : "<<solve(e1,e2,t,src,dest,n);
        if(i!=T) cout<<"\n";
    }
    return 0;
}

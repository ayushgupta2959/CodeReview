#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> create_graph(vector<vector<int>> &astronaut ,int n){
    vector<vector<int>> g(n,vector<int>());
    for(auto edge: astronaut){
        g[edge[0]].emplace_back(edge[1]);
        g[edge[1]].emplace_back(edge[0]);
    }
    return g;
}
int dfs(vector<vector<int>> &g,vector<bool> &visited,int node){
    visited[node] = true;
    int count = 1;
    for(auto x:g[node]){
        if(!visited[x]){
            count += dfs(g,visited,x);
        }
    }
    return count;
}
unsigned long long journeyToMoon(int n, vector<vector<int>> &astronaut) {

    if(n==1) return 0;

    vector<unsigned long long> count;
    vector<vector<int>> g = create_graph(astronaut,n);
    vector<bool> visited(n,false);
    for(int i=0;i<n;++i){
        if(!visited[i]){
            count.emplace_back(dfs(g,visited,i));
        }
    }
    //1st way
    unsigned long long result = 0;
    int c = count.size();
    for(int i=1;i<c;++i){
        count[i]+=count[i-1];
    }
    unsigned long long curr;
    for(int i=0;i<c-1;i++){
        curr = count[i];
        if(i>0) curr-=count[i-1];
        result += curr*(count[c-1]-count[i]);
    }
    //
    /*
    //2nd way
    //i.e selecting two from total in nC2 ways then subtracting ways in which astronaut belong to same country
    // number of ways to select two astronaut from same country  = count[i]C2
    result = n*(n-1)/2;
    for(int i=0;i<c.size();i++){
        result -= ((count[i])*(count[i-1)/2);
    }
    */
    return result;
}


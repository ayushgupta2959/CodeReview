#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define ll long long
void dfs_count(vector<vector<pi>> &g,int x,vector<int> &count,int parent){
	for(auto node:g[x]){
		if(node.first!=parent){
			dfs_count(g,node.first,count,x);
			count[x]+=count[node.first];
		}
	}
}
int min(int a,int b){
    return a<b?a:b;
}
ll dfs_result(vector<vector<pi>> &g,int x,int parent,vector<int> &count){
	ll result = 0;
	for(auto node:g[x]){
		if(node.first!=parent){
            result += dfs_result(g,node.first,x,count);
			result += (2LL*min(count[node.first],g.size()-count[node.first])*node.second);
		}
	}
	return result;
}
ll solve(vector<vector<pi>> &g){
	int n = g.size();
	//vector<bool> visited(n,false);
	vector<int> count(n,1);
	dfs_count(g,0,count,-1);
	//for(auto x:count) cout<<x<<"\n";
    return dfs_result(g,0,-1,count);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int T,n,x,y,z;
	cin>>T;
	for(int t=1;t<=T;++t){
		cin>>n;
		vector<vector<pi>> g(n,vector<pi>());
		for(int i=0;i<n-1;++i){
			cin>>x>>y>>z;
			g[x-1].emplace_back(make_pair(y-1,z));
			g[y-1].emplace_back(make_pair(x-1,z));
		}
		ll result = solve(g);
		cout<<"Case #"<<t<<": "<<result<<"\n";
	}
	return 0;
}

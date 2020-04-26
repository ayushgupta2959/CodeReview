#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))
#define EB emplace_back
#define W first
#define B second

vector<pair<int,int>> dp_in, dp_out;
vector<vector<pair<int,int>>> g;
vector<pair<int,int>> color;

void dfs1(int u, int p){
	dp_in[u] = color[u];
	int v;
	for(auto& row: g[u]){
		v = row.first;
		if(v^p){
			dfs1(v, u);
			if((dp_in[u].W - dp_in[u].B) < (dp_in[u].W - dp_in[u].B + dp_in[v].W - dp_in[v].B)){
				dp_in[u].W += dp_in[v].W;
				dp_in[u].B += dp_in[v].B;
				row.second = 1;
			}
		}
	}
}

void dfs2(int u, int p){
	int v;
	for(auto& row: g[u]){
		v = row.first;
		if(v^p){
			dp_out[v] = color[v];
			auto t = dp_in[u];
			if(row.second){
				t.W -= dp_in[v].W;
				t.B -= dp_in[v].B;
			}
			if((dp_out[v].W - dp_out[v].B) < (dp_out[v].W - dp_out[v].B + t.W - t.B + dp_out[u].W - dp_out[u].B - color[u].W + color[u].B)){
				dp_out[v].W += t.W + dp_out[u].W - color[u].W;
				dp_out[v].B += t.B + dp_out[u].B - color[u].B;
			}
			dfs2(v, u);
		}
	}
}


int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;
	color = vector<pair<int,int>>(n,{0,0});

	int x, y;
	for(int i = 0; i < n; ++i){
		cin>>x;
		if(x) color[i].W = 1;
		else color[i].B = 1;
	}

	g = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());
	
	for(int i = 1; i < n; ++i){
		cin>>x>>y;
		g[x-1].EB(y-1,0);
		g[y-1].EB(x-1,0);
	}

	dp_in = vector<pair<int,int>>(n+1, {0,0});
	dp_out = vector<pair<int,int>>(n+1, {0,0});

	dfs1(0,-1);
	dp_out[0] = color[0];
	dfs2(0,-1);

	// for(int i = 0;i<n;++i){
	// 	for(auto& row: g[i]){
	// 		cout<<row.first+1<<" "<<row.second<<", ";
	// 	}
	// 	cout<<"\n";
	// }

	// for(int i = 0; i < n; ++i){
	// 	cout<<i+1<<" "<<dp_in[i].W<<" "<<dp_in[i].B<<" "<<dp_out[i].W<<" "<<dp_out[i].B<<"\n";
	// }

	int result;
	for(int i = 0; i < n; ++i){
		auto t = color[i];
		result = max({dp_in[i].W - dp_in[i].B, dp_out[i].W - dp_out[i].B, dp_in[i].W - dp_in[i].B + dp_out[i].W - dp_out[i].B - t.W + t.B});
		cout<<result<<" ";
	}

  	return 0;
}
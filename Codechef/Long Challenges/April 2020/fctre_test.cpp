#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2") 
#define SP ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define FF first
#define SS second
#define EB emplace_back
using LL = long long;
using pi = pair<int,int>;

int mxN = 1e6+5;
vector<int> PF(mxN+1); // for getting prime factorization of a number
vector<vector<int>> g;
int N;
int MOD = 1e9+7;
vector<int> a(mxN+1);
vector<vector<pi>> dp(mxN+1, vector<pi>());
vector<vector<pi>> pre_factors_all(mxN+1);
vector<vector<pi>> Q;
vector<LL> result;
vector<int> ancestor(mxN);
vector<bool> visited(mxN);

///////disjoint set////////////////////////
vector<int> parent_root(mxN);
vector<int> rank_root(mxN);

int find_root(int x){
	while(x != parent_root[x]){
		parent_root[x] = parent_root[parent_root[x]];
		x = parent_root[x];
	}
	return x;
}

bool is_same_root(int x, int y){
	return find_root(x) == find_root(y);
}

void union_roots(int x, int y){
	int root_x = find_root(x);
	int root_y = find_root(y);

	if(root_x == root_y) return;

	if(rank_root[root_x] > rank_root[root_y]){
		parent_root[root_y] = root_x;
	}
	else{
		parent_root[root_x] = root_y;
		if(rank_root[root_x] == rank_root[root_y]) rank_root[root_y]++;
	}
}

//////////////////////////////

void add_factors(vector<pi>& a, vector<pi>& b){
	int ai = 0, bi = 0, an = a.size(), bn = b.size();
	vector<pi> res;
	res.reserve(an+bn);
	while(ai < an && bi < bn){
		if(a[ai].FF < b[bi].FF){
			res.EB(a[ai]);
			ai++;
		}
		else if(a[ai].FF > b[bi].FF){
			res.EB(b[bi]);
			bi++;
		}
		else{
			res.EB(a[ai].FF, a[ai].SS + b[bi].SS);
			ai++;
			bi++;
		}
	}

	while(ai < an){
		res.EB(a[ai]);
		ai++;
	}

	while(bi < bn){
		res.EB(b[bi]);
		bi++;
	}
	a = res;
}

void sub_factors(vector<pi>& a, vector<pi>& b){
	int ai = 0, bi = 0, an = a.size(), bn = b.size();
	vector<pi> res;
	res.reserve(an);
	while(ai < an && bi < bn){
		if(a[ai].FF < b[bi].FF){
			res.EB(a[ai]);
			ai++;
		}
		else if(a[ai].FF > b[bi].FF){
			exit(0); //this should never happen
		}
		else{
			if(a[ai].SS - b[bi].SS) res.EB(a[ai].FF, a[ai].SS - b[bi].SS);
			ai++;
			bi++;
		}
	}

	while(ai < an){
		res.EB(a[ai]);
		ai++;
	}

	while(bi < bn){
		exit(0); // this should never happen
	}

	a = res;
}

void dfs1(int u, int p){

    dp[u] = pre_factors_all[a[u]];
	add_factors(dp[u], dp[p]);

	ancestor[u] = u;
	visited[u] = true;

	for(auto& v: g[u]){
		if(v^p){
			dfs1(v, u);
			union_roots(u, v);
			ancestor[find_root(u)] = u;
		}
	}

	int lca;
    vector<pi> res;
	LL fac_count;
	for(auto& q: Q[u]){
		if(visited[q.FF]){
			if(result[q.SS] != -1ll) continue;
			lca = ancestor[find_root(q.FF)];
			res = dp[u];
			add_factors(res, dp[q.FF]);
			sub_factors(res, dp[lca]);
			sub_factors(res, dp[lca]);
			add_factors(res, pre_factors_all[a[lca]]);
			fac_count = 1;
			for(auto& x: res){
				fac_count = (fac_count*(x.SS+1))%MOD;
			}
			result[q.SS] = fac_count;
		}
	}
}



void pre(){
	for(int i = 0; i <= mxN; ++i) PF[i] = i;

	for(int i = 2; i <= mxN; i+=2) PF[i] = 2;

	for(int i = 3; i*i <= mxN; i += 2){
		if(PF[i] == i){
			for(int j = i*i; j <= mxN; j += 2*i){
				PF[j] = i;
			}
		}
	}

	for(int i = 2; i <= mxN; ++i){
        vector<pi> res = {make_pair(PF[i],1)};
		add_factors(res, pre_factors_all[i/PF[i]]);
		pre_factors_all[i] = res;
	}
}

void solve(){
	cin>>N;
	g.assign(N+1, vector<int>());
	Q.assign(N+1, vector<pi>());
	rank_root.assign(N+1, 0);

	for(int i = 1; i <= N; ++i){
		parent_root[i] = i;
		visited[i] = false;
	}

	int X,Y;
	for(int i = 1; i < N; ++i){
		cin>>X>>Y;
		g[X].EB(Y);
		g[Y].EB(X);
	}

	for(int i = 1; i <= N; ++i) cin>>a[i];

	int q;
	cin>>q;
	for(int i = 0; i < q; ++i){
		cin>>X>>Y;
		Q[X].EB(Y, i);
		Q[Y].EB(X, i);
	}

	result.assign(q, -1);

	dfs1(1, 0);
	for(auto& ans: result) cout<<ans<<"\n";
}

int main() {
	SP;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	pre();

	int t;
	cin>>t;
	while(t--){
		solve();
	}

  	return 0;
}
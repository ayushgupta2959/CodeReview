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
    cout<<"dfs completed\n";
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

// 
//NO effect from changing the segtree implementation from recursive to iterative on execution time
// // only effect on amount of memory consumed during execution which in iterative case was almost halved

// #include <bits/stdc++.h>
// using namespace std;

// #define SP ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
// #define FF first
// #define SS second
// #define EB emplace_back
// using LL = long long;
// using pi = pair<int,int>;

// int mxN = 1e6+5;
// vector<int> PF(mxN+1); // for getting prime factorization of a number
// vector<vector<int>> g;
// int N;
// int MOD = 1e9+7;
// vector<int> a(mxN+1);
// vector<vector<pi>> dp(mxN+1, vector<pi>());
// vector<vector<pi>> pre_factors_all(mxN+1);

// vector<int> euler, height(mxN), first(mxN), seg_tree;

// void build(){
// 	int n = euler.size();
// 	int left_val, right_val;
// 	for(int i = 0; i < n; ++i){
// 		seg_tree[n+i] = euler[i];
// 	}
// 	for(int i = n-1; i ; i--){
// 		left_val = seg_tree[i<<1];
// 		right_val = seg_tree[(i<<1)|1];
// 		seg_tree[i] = (height[left_val] < height[right_val]) ? left_val : right_val;
// 	}
// }

// int query(int l, int r){
// 	l += euler.size();
// 	r += euler.size();
// 	int res = 0;
// 	for(; l < r; l >>= 1, r >>= 1){
// 		if(l&1){
// 			res = (height[res] < height[seg_tree[l]]) ? res : seg_tree[l];
// 			l++;
// 		}
// 		if(r&1){
// 			--r;
// 			res = (height[res] < height[seg_tree[r]]) ? res : seg_tree[r];
// 		}
// 	}
// 	return res;
// }

// int get_lca(int u, int v){
// 	int ql = first[u];
// 	int qr = first[v];
// 	if(ql > qr) swap(ql, qr);
// 	return query(ql, qr+1);
// }

// void add_factors(vector<pi>& a, vector<pi>& b){
// 	int ai = 0, bi = 0, an = a.size(), bn = b.size();
// 	vector<pi> res;
// 	res.reserve(an+bn);
// 	while(ai < an && bi < bn){
// 		if(a[ai].FF < b[bi].FF){
// 			res.EB(a[ai]);
// 			ai++;
// 		}
// 		else if(a[ai].FF > b[bi].FF){
// 			res.EB(b[bi]);
// 			bi++;
// 		}
// 		else{
// 			res.EB(a[ai].FF, a[ai].SS + b[bi].SS);
// 			ai++;
// 			bi++;
// 		}
// 	}

// 	while(ai < an){
// 		res.EB(a[ai]);
// 		ai++;
// 	}

// 	while(bi < bn){
// 		res.EB(b[bi]);
// 		bi++;
// 	}
// 	a = res;
// }

// void sub_factors(vector<pi>& a, vector<pi>& b){
// 	int ai = 0, bi = 0, an = a.size(), bn = b.size();
// 	vector<pi> res;
// 	res.reserve(an);
// 	while(ai < an && bi < bn){
// 		if(a[ai].FF < b[bi].FF){
// 			res.EB(a[ai]);
// 			ai++;
// 		}
// 		else if(a[ai].FF > b[bi].FF){
// 			exit(0); //this should never happen
// 		}
// 		else{
// 			if(a[ai].SS - b[bi].SS) res.EB(a[ai].FF, a[ai].SS - b[bi].SS);
// 			ai++;
// 			bi++;
// 		}
// 	}

// 	while(ai < an){
// 		res.EB(a[ai]);
// 		ai++;
// 	}

// 	while(bi < bn){
// 		exit(0); // this should never happen
// 	}

// 	a = res;
// }

// void dfs1(int u, int p, int h, vector<pi> csum){
// 	height[u] = h;
// 	first[u] = euler.size();
// 	euler.EB(u);
// 	add_factors(csum, pre_factors_all[a[u]]);
// 	dp[u] = csum;
// 	for(auto& v: g[u]){
// 		if(v^p){
// 			dfs1(v, u, h+1, csum);
// 			euler.EB(u);
// 		}
// 	}
// }

// void init_euler_for_LCA(){
// 	euler = vector<int>();
// 	vector<pi> csum;
// 	dfs1(1, 0, 0, csum);

// 	int m = euler.size();
// 	seg_tree.assign(2*m, 0);
// 	build();
// }

// void pre(){
// 	for(int i = 0; i <= mxN; ++i) PF[i] = i;

// 	for(int i = 2; i <= mxN; i+=2) PF[i] = 2;

// 	for(int i = 3; i*i <= mxN; i += 2){
// 		if(PF[i] == i){
// 			for(int j = i*i; j <= mxN; j += 2*i){
// 				PF[j] = i;
// 			}
// 		}
// 	}

// 	for(int i = 2; i <= mxN; ++i){
//         vector<pi> res = {make_pair(PF[i],1)};
// 		add_factors(res, pre_factors_all[i/PF[i]]);
// 		pre_factors_all[i] = res;
// 	}

// 	height[0] = INT_MAX;
// }

// void solve(){
// 	cin>>N;
// 	g.assign(N+1, vector<int>());

// 	int X,Y;
// 	for(int i = 1; i < N; ++i){
// 		cin>>X>>Y;
// 		g[X].EB(Y);
// 		g[Y].EB(X);
// 	}

// 	for(int i = 1; i <= N; ++i) cin>>a[i];

// 	// Euler tour for LCA computation
// 	init_euler_for_LCA();

// 	////////////////////////////////////////
// 	//testing code to remove
// 	// int m = euler.size();
// 	// for(int i = 0; i < m; ++i) cout<<euler[i];
// 	// for
// 	// for(auto& x:)

// 	////////////////////////////////////////

// 	int q, u, v, lca;
// 	LL fac_count;
// 	cin>>q;
// 	while(q--){
// 		cin>>u>>v;
// 		lca = get_lca(u,v);
// 		vector<pi> res;
// 		add_factors(res, dp[u]);
// 		add_factors(res, dp[v]);
// 		sub_factors(res, dp[lca]);
// 		sub_factors(res, dp[lca]);
// 		add_factors(res, pre_factors_all[a[lca]]);
// 		fac_count = 1;
// 		for(auto& x: res){
// 			fac_count = (fac_count*(x.SS+1))%MOD;
// 		}
// 		cout<<fac_count<<"\n";
// 	}
// }

// int main() {
// 	SP;

// 	////////////////To Remove//////////////
// 	// freopen("../../../input.txt", "r", stdin);
// 	// freopen("../../../output.txt", "w", stdout);
// 	///////////////////////////////////////

// 	pre();

// 	int t;
// 	cin>>t;
// 	while(t--){
// 		solve();
// 	}

//   	return 0;
// }

// // #include <bits/stdc++.h>
// // using namespace std;

// // #define SP ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
// // #define FF first
// // #define SS second
// // #define EB emplace_back
// // using LL = long long;
// // using pi = pair<int,int>;


// // int mxN = 1e6+5;
// // vector<int> PF(mxN+1); // for getting prime factorization of a number
// // vector<vector<int>> g;
// // int N;
// // int MOD = 1e9+7;
// // vector<int> a(mxN+1);
// // vector<vector<pi>> dp(mxN+1, vector<pi>());
// // vector<vector<pi>> pre_factors_all(mxN+1);

// // vector<int> euler, height(mxN), first(mxN), seg_tree;

// // void build(int i, int l, int r){
// // 	if(l == r){
// // 		seg_tree[i] = euler[l];
// // 		return;
// // 	}
// // 	int m = (l+r)>>1;
// // 	build(i<<1, l, m);
// // 	build((i<<1)|1, m+1, r);
// // 	int left_val = seg_tree[i<<1];
// // 	int right_val = seg_tree[(i<<1)|1];
// // 	seg_tree[i] = (height[left_val] < height[right_val]) ? left_val : right_val;
// // }

// // int query(int i, int l, int r, int& ql, int& qr){
// // 	if(qr < l || r < ql) return -1;
// // 	if(ql <=l && qr >= r) return seg_tree[i];

// // 	int m = (l+r)>>1;
// // 	int left_val = query(i<<1, l, m, ql, qr);
// // 	int right_val = query((i<<1)|1, m+1, r, ql, qr);

// // 	if(left_val == -1) return right_val;
// // 	if(right_val == -1) return left_val;

// // 	return (height[left_val] < height[right_val])? left_val : right_val;
// // }

// // int get_lca(int u, int v){
// // 	int ql = first[u];
// // 	int qr = first[v];
// // 	if(ql > qr) swap(ql, qr);
// // 	return query(1, 0, euler.size()-1, ql, qr);
// // }
// // void add_factors(vector<pi>& a, vector<pi>& b){
// // 	int ai = 0, bi = 0, an = a.size(), bn = b.size();
// // 	vector<pi> res;
// // 	res.reserve(an+bn);
// // 	while(ai < an && bi < bn){
// // 		if(a[ai].FF < b[bi].FF){
// // 			res.EB(a[ai]);
// // 			ai++;
// // 		}
// // 		else if(a[ai].FF > b[bi].FF){
// // 			res.EB(b[bi]);
// // 			bi++;
// // 		}
// // 		else{
// // 			res.EB(a[ai].FF, a[ai].SS + b[bi].SS);
// // 			ai++;
// // 			bi++;
// // 		}
// // 	}

// // 	while(ai < an){
// // 		res.EB(a[ai]);
// // 		ai++;
// // 	}

// // 	while(bi < bn){
// // 		res.EB(b[bi]);
// // 		bi++;
// // 	}
// // 	a = res;
// // }

// // void sub_factors(map<int,int>& a, map<int,int>& b){
// // 	int ai = 0, bi = 0, an = a.size(), bn = b.size();
// // 	vector<pi> res;
// // 	res.reserve(an);
// // 	while(ai < an && bi < bn){
// // 		if(a[ai].FF < b[bi].FF){
// // 			res.EB(a[ai]);
// // 			ai++;
// // 		}
// // 		else if(a[ai].FF > b[bi].FF){
// // 			exit(0); //this should never happen
// // 		}
// // 		else{
// // 			if(a[ai].SS - b[bi].SS) res.EB(a[ai].FF, a[ai].SS - b[bi].SS);
// // 			ai++;
// // 			bi++;
// // 		}
// // 	}

// // 	while(ai < an){
// // 		res.EB(a[ai]);
// // 		ai++;
// // 	}

// // 	while(bi < bn){
// // 		exit(0); // this should never happen
// // 	}

// // 	a = res;
// // }

// // void dfs1(int u, int p, int h, vector<pi> csum){
// // 	height[u] = h;
// // 	first[u] = euler.size();
// // 	euler.EB(u);
// // 	add_factors(csum, pre_factors_all[a[u]]);
// // 	dp[u] = csum;
// // 	for(auto& v: g[u]){
// // 		if(v^p){
// // 			dfs1(v, u, h+1, csum);
// // 			euler.EB(u);
// // 		}
// // 	}
// // }

// // void init_euler_for_LCA(){
// // 	euler = vector<int>();
// // 	vector<pi> csum;
// // 	dfs1(1, 0, 0, csum);

// // 	int m = euler.size();
// // 	seg_tree.assign(4*m);
// // 	build(1, 0, m-1);
// // }

// // void pre(){
// // 	for(int i = 0; i <= mxN; ++i) PF[i] = i;

// // 	for(int i = 2; i <= mxN; i+=2) PF[i] = 2;

// // 	for(int i = 3; i*i <= mxN; i += 2){
// // 		if(PF[i] == i){
// // 			for(int j = i*i; j <= mxN; j += 2*i){
// // 				PF[j] = i;
// // 			}
// // 		}
// // 	}

// // 	for(int i = 2; i <= mxN; ++i){
// // 		vector<pi> res
// // 		res[PF[i]]++;
// // 		add_factors(res, pre_factors_all[i/PF[i]]);
// // 		pre_factors_all[i] = res;
// // 	}
// // }

// // void solve(){
// // 	cin>>N;
// // 	g.assign(N+1, vector<int>());

// // 	int X,Y;
// // 	for(int i = 1; i < N; ++i){
// // 		cin>>X>>Y;
// // 		g[X].EB(Y);
// // 		g[Y].EB(X);
// // 	}

// // 	for(int i = 1; i <= N; ++i) cin>>a[i];

// // 	// Euler tour for LCA computation
// // 	init_euler_for_LCA();

// // 	int q, u, v, lca;
// // 	LL fac_count;
// // 	cin>>q;
// // 	while(q--){
// // 		cin>>u>>v;
// // 		lca = get_lca(u,v);
// // 		vector<pi> res;
// // 		add_factors(res, dp[u]);
// // 		add_factors(res, dp[v]);
// // 		sub_factors(res, dp[lca]);
// // 		sub_factors(res, dp[lca]);
// // 		add_factors(res, pre_factors_all[a[lca]]);
// // 		fac_count = 1;
// // 		for(auto& x: res){
// // 			fac_count = (fac_count*(x.SS+1))%MOD;
// // 		}
// // 		cout<<fac_count<<"\n";
// // 	}
// // }

// // int main() {
// // 	SP;

// // 	////////////////To Remove//////////////
// // 	// freopen("../../../input.txt", "r", stdin);
// // 	// freopen("../../../output.txt", "w", stdout);
// // 	///////////////////////////////////////

// // 	pre();

// // 	int t;
// // 	cin>>t;
// // 	while(t--){
// // 		solve();
// // 	}

// //   	return 0;
// // }
// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // #define SP ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
// // // #define FF first
// // // #define SS second
// // // #define EB emplace_back
// // // using LL = long long;
// // // using pi = pair<int,int>;


// // // int mxN = 1e6+5;
// // // vector<int> PF(mxN+1); // for getting prime factorization of a number
// // // vector<int> a;
// // // vector<vector<int>> g;
// // // int N;
// // // int MOD = 1e9+7;

// // // vector<int> euler, height, first, seg_tree;

// // // vector<map<int,int>> dp;
// // // vector<map<int,int>> pre_factors_all(mxN+1);

// // // void build(int i, int l, int r){
// // // 	if(l == r){
// // // 		seg_tree[i] = euler[l];
// // // 		return;
// // // 	}
// // // 	int m = (l+r)>>1;
// // // 	build(i<<1, l, m);
// // // 	build((i<<1)|1, m+1, r);
// // // 	int left_val = seg_tree[i<<1];
// // // 	int right_val = seg_tree[(i<<1)|1];
// // // 	seg_tree[i] = (height[left_val] < height[right_val]) ? left_val : right_val;
// // // }

// // // int query(int i, int l, int r, int& ql, int& qr){
// // // 	if(qr < l || r < ql) return -1;
// // // 	if(ql <=l && qr >= r) return seg_tree[i];

// // // 	int m = (l+r)>>1;
// // // 	int left_val = query(i<<1, l, m, ql, qr);
// // // 	int right_val = query((i<<1)|1, m+1, r, ql, qr);

// // // 	if(left_val == -1) return right_val;
// // // 	if(right_val == -1) return left_val;

// // // 	return (height[left_val] < height[right_val])? left_val : right_val;

// // // }

// // // int get_lca(int u, int v){
// // // 	int ql = first[u];
// // // 	int qr = first[v];
// // // 	if(ql > qr) swap(ql, qr);
// // // 	return query(1, 0, euler.size()-1, ql, qr);
// // // }
// // // void add_factors(map<int,int>& a, map<int,int>& b){
// // // 	for(auto& x: b){
// // // 		a[x.FF] += x.SS;
// // // 	}
// // // }

// // // void sub_factors(map<int,int>& a, map<int,int>& b){
// // // 	for(auto& x: b){
// // // 		a[x.FF] -= x.SS;
// // // 	}
// // // }

// // // void dfs1(int u, int p, int h, map<int,int> csum){
// // // 	height[u] = h;
// // // 	first[u] = euler.size();
// // // 	euler.EB(u);
// // // 	add_factors(csum, pre_factors_all[a[u]]);
// // // 	dp[u] = csum;
// // // 	for(auto& v: g[u]){
// // // 		if(v^p){
// // // 			dfs1(v, u, h+1, csum);
// // // 			euler.EB(u);
// // // 		}
// // // 	}
// // // }

// // // void init_euler_for_LCA(){
// // // 	euler = vector<int>();
// // // 	height = vector<int>(N+1);
// // // 	first = vector<int>(N+1);
// // // 	map<int,int> csum;
// // // 	dfs1(1, 0, 0, csum);

// // // 	int m = euler.size();
// // // 	seg_tree = vector<int>(4*m);
// // // 	build(1, 0, m-1);
// // // }

// // // void pre(){
// // // 	for(int i = 0; i <= mxN; ++i) PF[i] = i;

// // // 	for(int i = 2; i <= mxN; i+=2) PF[i] = 2;

// // // 	for(int i = 3; i*i <= mxN; i += 2){
// // // 		if(PF[i] == i){
// // // 			for(int j = i*i; j <= mxN; j += 2*i){
// // // 				PF[j] = i;
// // // 			}
// // // 		}
// // // 	}

// // // 	for(int i = 2; i <= mxN; ++i){
// // // 		map<int,int> res;
// // // 		res[PF[i]]++;
// // // 		add_factors(res, pre_factors_all[i/PF[i]]);
// // // 		pre_factors_all[i] = res;
// // // 	}
// // // }

// // // void solve(){
// // // 	cin>>N;
// // // 	a = vector<int>(N+1);
// // // 	g = vector<vector<int>>(N+1, vector<int>());

// // // 	int X,Y;
// // // 	for(int i = 1; i < N; ++i){
// // // 		cin>>X>>Y;
// // // 		g[X].EB(Y);
// // // 		g[Y].EB(X);
// // // 	}

// // // 	for(int i = 1; i <= N; ++i) cin>>a[i];

// // // 	// Euler tour for LCA computation
// // // 	dp = vector<map<int,int>>(N+1);
// // // 	init_euler_for_LCA();

// // // 	int q, u, v, lca;
// // // 	LL fac_count;
// // // 	cin>>q;
// // // 	while(q--){
// // // 		cin>>u>>v;
// // // 		lca = get_lca(u,v);
// // // 		map<int,int> res;
// // // 		add_factors(res, dp[u]);
// // // 		add_factors(res, dp[v]);
// // // 		sub_factors(res, dp[lca]);
// // // 		sub_factors(res, dp[lca]);
// // // 		add_factors(res, pre_factors_all[a[lca]]);
// // // 		fac_count = 1;
// // // 		for(auto& x: res){
// // // 			fac_count = (fac_count*(x.SS+1))%MOD;
// // // 		}
// // // 		cout<<fac_count<<"\n";
// // // 	}
// // // }

// // // int main() {
// // // 	SP;

// // // 	////////////////To Remove//////////////
// // // 	// freopen("../../../input.txt", "r", stdin);
// // // 	// freopen("../../../output.txt", "w", stdout);
// // // 	///////////////////////////////////////

// // // 	pre();

// // // 	int t;
// // // 	cin>>t;
// // // 	while(t--){
// // // 		solve();
// // // 	}

// // //   	return 0;
// // // }

// // // // #include <bits/stdc++.h>
// // // // using namespace std;

// // // // #define SP ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
// // // // #define LL long long
// // // // #define FF first
// // // // #define SS second
// // // // #define EB emplace_back


// // // // int mxN = 1e6+5;
// // // // vector<int> PF(mxN+1); // for getting prime factorization of a number
// // // // vector<int> a;
// // // // vector<vector<int>> g;
// // // // int N;
// // // // int MOD = 1e9+7;

// // // // vector<int> euler, height, first, seg_tree;

// // // // vector<map<int,int>> dp;
// // // // vector<map<int,int>> pre_factors_all(mxN+1);
// // // // // vector<map<int,int>> factors;

// // // // // map<int,int> get_factorization(int num){
// // // // // 	map<int,int> res;
// // // // // 	while(num != 1){
// // // // // 		res[PF[num]]++;
// // // // // 		num /= PF[num];
// // // // // 	}
// // // // // 	return res;
// // // // // }



// // // // // int left(int i){return i<<1;}
// // // // // int right(int i){return (i<<1)|1;}

// // // // void build(int i, int l, int r){
// // // // 	if(l == r){
// // // // 		seg_tree[i] = euler[l];
// // // // 		return;
// // // // 	}
// // // // 	int m = (l+r)>>1;
// // // // 	build(i<<1, l, m);
// // // // 	build((i<<1)|1, m+1, r);
// // // // 	int left_val = seg_tree[i<<1];
// // // // 	int right_val = seg_tree[(i<<1)|1];
// // // // 	seg_tree[i] = (height[left_val] < height[right_val]) ? left_val : right_val;
// // // // }

// // // // int query(int i, int l, int r, int& ql, int& qr){
// // // // 	if(qr < l || r < ql) return -1;
// // // // 	if(ql <=l && qr >= r) return seg_tree[i];

// // // // 	int m = (l+r)>>1;
// // // // 	int left_val = query(i<<1, l, m, ql, qr);
// // // // 	int right_val = query((i<<1)|1, m+1, r, ql, qr);

// // // // 	if(left_val == -1) return right_val;
// // // // 	if(right_val == -1) return left_val;

// // // // 	return (height[left_val] < height[right_val])? left_val : right_val;

// // // // }

// // // // int get_lca(int u, int v){
// // // // 	int ql = first[u];
// // // // 	int qr = first[v];
// // // // 	if(ql > qr) swap(ql, qr);
// // // // 	return query(1, 0, euler.size()-1, ql, qr);
// // // // }
// // // // void add_factors(map<int,int>& a, map<int,int>& b){
// // // // 	for(auto& x: b){
// // // // 		a[x.FF] += x.SS;
// // // // 	}
// // // // }

// // // // void sub_factors(map<int,int>& a, map<int,int>& b){
// // // // 	for(auto& x: b){
// // // // 		a[x.FF] -= x.SS;
// // // // 	}
// // // // }

// // // // void dfs1(int u, int p, int h, map<int,int> csum){
// // // // 	height[u] = h;
// // // // 	first[u] = euler.size();
// // // // 	euler.EB(u);
// // // // 	add_factors(csum, pre_factors_all[a[u]]);
// // // // 	dp[u] = csum;
// // // // 	for(auto& v: g[u]){
// // // // 		if(v^p){
// // // // 			dfs1(v, u, h+1, csum);
// // // // 			euler.EB(u);
// // // // 		}
// // // // 	}
// // // // }

// // // // void init_euler_for_LCA(){
// // // // 	euler = vector<int>();
// // // // 	height = vector<int>(N+1);
// // // // 	first = vector<int>(N+1);
// // // // 	map<int,int> csum;
// // // // 	dfs1(1, 0, 0, csum);

// // // // 	int m = euler.size();
// // // // 	seg_tree = vector<int>(4*m);
// // // // 	build(1, 0, m-1);
// // // // }



// // // // // void dfs2(int u, int p, map<int,int> csum){
// // // // // 	add_factors(csum, pre_factors_all[a[u]]);
// // // // // 	dp[u] = csum;
// // // // // 	for(auto& v: g[u]){
// // // // // 		if(v^p){
// // // // // 			dfs2(v, u, csum);
// // // // // 		}
// // // // // 	}
// // // // // }

// // // // // void generate_all_root_to_leaf_factors_csum(){
// // // // // 	map<int,int> csum;
// // // // // 	dfs2(1, 0, csum);
// // // // // }

// // // // void pre(){
// // // // 	for(int i = 0; i <= mxN; ++i) PF[i] = i;

// // // // 	for(int i = 2; i <= mxN; i+=2) PF[i] = 2;

// // // // 	for(int i = 3; i*i <= mxN; i += 2){
// // // // 		if(PF[i] == i){
// // // // 			for(int j = i*i; j <= mxN; j += 2*i){
// // // // 				PF[j] = i;
// // // // 			}
// // // // 		}
// // // // 	}

// // // // 	for(int i = 2; i <= mxN; ++i){
// // // // 		map<int,int> res;
// // // // 		res[PF[i]]++;
// // // // 		add_factors(res, pre_factors_all[i/PF[i]]);
// // // // 		pre_factors_all[i] = res;
// // // // 	}
// // // // }

// // // // void solve(){
// // // // 	cin>>N;
// // // // 	a = vector<int>(N+1);
// // // // 	g = vector<vector<int>>(N+1, vector<int>());

// // // // 	int X,Y;
// // // // 	for(int i = 1; i < N; ++i){
// // // // 		cin>>X>>Y;
// // // // 		g[X].EB(Y);
// // // // 		g[Y].EB(X);
// // // // 	}

// // // // 	for(int i = 1; i <= N; ++i) cin>>a[i];

// // // // 	// factors = vector<map<int,int>>(N+1);

// // // // 	// for(int i = 1; i <= N; ++i){
// // // // 	// 	factors[i] = get_factorization(a[i]);
// // // // 	// }

// // // // 	// Euler tour for LCA computation
// // // // 	dp = vector<map<int,int>>(N+1);
// // // // 	init_euler_for_LCA();

// // // // 	// generate_all_root_to_leaf_factors_csum();

// // // // 	int q, u, v, lca;
// // // // 	LL fac_count;
// // // // 	cin>>q;
// // // // 	while(q--){
// // // // 		cin>>u>>v;
// // // // 		lca = get_lca(u,v);
// // // // 		map<int,int> res;
// // // // 		add_factors(res, dp[u]);
// // // // 		add_factors(res, dp[v]);
// // // // 		sub_factors(res, dp[lca]);
// // // // 		sub_factors(res, dp[lca]);
// // // // 		add_factors(res, pre_factors_all[a[lca]]);
// // // // 		fac_count = 1;
// // // // 		for(auto& x: res){
// // // // 			fac_count = (fac_count*(x.SS+1))%MOD;
// // // // 		}
// // // // 		cout<<fac_count<<"\n";
// // // // 	}
// // // // }

// // // // int main() {
// // // // 	SP;

// // // // 	////////////////To Remove//////////////
// // // // 	// freopen("../../../input.txt", "r", stdin);
// // // // 	// freopen("../../../output.txt", "w", stdout);
// // // // 	///////////////////////////////////////

// // // // 	pre();

// // // // 	int t;
// // // // 	cin>>t;
// // // // 	while(t--){
// // // // 		solve();
// // // // 	}

// // // //   	return 0;
// // // // }
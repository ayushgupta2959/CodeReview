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
#define ll long long

int p = 1e9+7;
vector<ll> fact;
vector<ll> inv_fact;

ll mod_pow(ll a, ll b){
	ll result = 1;
	while(b){
		if(b&1) result = (result*a)%p;
		a = (a*a)%p;
		b>>=1;
	}
	return result;
}

ll inverse_modulo(ll x){
	return mod_pow(x,p-2);
}

void dfs1(int u, int p, vector<vector<int>> &g, vector<ll> &dp_in, vector<ll> &result){
	dp_in[u] = 1;
	for(auto& v: g[u]){
		if(v^p){
			dfs1(v,u,g,dp_in,result);
			dp_in[u] += dp_in[v];
		}
	}
}

void dfs2(int u, int p, vector<vector<int>> &g, vector<ll> &dp_in, vector<ll> &dp_out, vector<ll> &result){
	result[u] = fact[n-1];
	for(auto& v: g[u]){
		if(v^p){
			dp_out[v] = dp_in[u] - dp_in[v] + dp_out[u];
			result[u] = result[u]*
			// result[v] = (((result[u]*result[v])%p) * inv_fact[dp_out[v]])%p;

			dfs2(v,u,g,dp_in, dp_out,result);
		}
	}
}

int main() {
	sp;

	////////////////To Remove//////////////
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n, a, b;
	cin>>n;
	vector<vector<int>> g(n+1,vector<int>());

	for(int i = 1; i < n; ++i){
		cin>>a>>b;
		g[a].EB(b);
		g[b].EB(a);
	}

	fact = vector<ll>(n+1,1);
	inv_fact = vector<ll>(n+1, 1);
	for(int i = 2; i <= n; ++i){
		fact[i] = (fact[i-1]*i)%p;
		inv_fact[i] = inverse_modulo(fact[i]);
	}

	vector<ll> dp_in(n+1, 0), dp_out(n+1, 0),result(n+1,1);
	dfs1(1,0,g,dp_in,result);

	dfs2(1,0,g,dp_in,dp_out,result);
	// for(int i = 1; i <=n; ++i) cout<<dp_out[i]<<"\n";
	// for(int i = 1; i <=n; ++i) cout<<result[i]<<"\n";

  	return 0;
}
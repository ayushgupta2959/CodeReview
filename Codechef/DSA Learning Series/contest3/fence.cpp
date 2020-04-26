#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define FF first
#define SS second
#define pi pair<int,int>

vector<int> dirx = {-1, 0, 1, 0};
vector<int> diry = {0, -1, 0, 1};
int N, M;

bool is_valid(int x, int y, map<pi, bool> &a){
	if(x <= 0 || y <= 0 || x > N || y > M) return false;
	if(a.count({x, y}) == 0) return false;
	return true;
}

int dfs(int x, int y, map<pi, bool> &a){
	a[{x, y}] = true;
	int n_x, n_y;
	int res = 0;
	for(int i = 0; i < 4; ++i){
		n_x = x + dirx[i];
		n_y = y + diry[i];
		if(!is_valid(n_x, n_y, a)){
			res++;
			continue;
		}
		if(a[{n_x, n_y}]) continue;
		res += dfs(n_x, n_y, a);
	}
	return res;
}

void solve(){
	int k, x, y;
	cin>>N>>M>>k;

	map<pi, bool> a;
	while(k--){
		cin>>x>>y;
		a[{x, y}] = false;
	}

	int res = 0;
	for(auto& node: a){
		if(node.SS) continue;
		res += dfs(node.FF.FF, node.FF.SS, a);
	}

	cout<<res;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define EB emplace_back
#define pi pair<int, int>
#define FF first
#define SS second

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;
	vector<vector<pi>> g(n+1, vector<pi>());
	int x, y;
	for(int i = 1; i < n; ++i){
		cin>>x>>y;
		g[x].EB(make_pair(y, i));
		g[y].EB(make_pair(x, i));
	}

	if(n == 2){
		cout<<0;
		return 0;
	}

	int to_set = 0;
	vector<int> res(n, -1);



	for(int i = 1; i <= n; ++i){
		if(g[i].size()==1){
			res[g[i][0].SS] = to_set;
			to_set++;
		}
	}

	for(int i = 1; i < n; ++i){
		if(res[i] == -1){
			cout<<to_set;
			to_set++;
		}
		else cout<<res[i];
		cout<<"\n";
	}
  	return 0;
}
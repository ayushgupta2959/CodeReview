#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define SS second
void solve(){
	int n;
	cin>>n;
	unordered_map<int,int> m;
	int e;
	for(int i = 0; i < n; ++i){
		cin>>e;
		m[e]++;
	}
	int max_distinct = m.size();
	int max_equal = 0;
	for(auto& x: m){
		max_equal = max(max_equal, x.SS);
	}
	int res = max({min(max_distinct-1, max_equal-1), min(max_distinct, max_equal-1), min(max_distinct-1, max_equal)});
	cout<<res;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}
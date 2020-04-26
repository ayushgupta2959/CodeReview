#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n, x, y;
	cin>>n>>x>>y;
	vector<int> start(n), end(n), v(x), w(y);

	for(int i = 0; i < n; ++i){
		cin>>start[i]>>end[i];
	}

	for(auto& x: v) cin>>x;

	for(auto& x: w) cin>>x;

	sort(v.rbegin(), v.rend());
	sort(w.begin(), w.end());

	int res = INT_MAX;

	for(int i = 0; i < n; ++i){
		auto s = lower_bound(v.begin(), v.end(), start[i], greater<int>());
		if(s == v.end()) continue;
		auto e = lower_bound(w.begin(), w.end(), end[i]);
		if(e == w.end()) continue;
		res = min(res, (*e) - (*s) + 1);

	}	

	cout<<res;

  	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define pi pair<int,int>
#define EB emplace_back
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
	vector<pi> a(n);
	vector<bool> distinct_y(501, false);
	int mxN = 100000;

	int x, y;
	for(int i = 0; i < n; ++i){
		cin>>x>>y;
		a[i] = {x, y};
		distinct_y[y] = true;
	}

	distinct_y[500] = true;

	int ans = 0;
	int tn;
	for(int i = 1; i < 501; ++i){
		if(!distinct_y[i]) continue;

		vector<int> t;
		t.EB(0);
		for(auto& p: a){
			if(p.SS < i){
				t.EB(p.FF);
			}
		}
		t.EB(mxN);
		tn = t.size();

		for(int j = 1; j < tn; ++j){
			ans = max(ans, (t[j] - t[j-1])*i);
		}
	}

	cout<<ans;

  	return 0;
}
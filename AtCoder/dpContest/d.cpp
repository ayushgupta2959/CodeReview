#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int n, w;

	cin>>n>>w;

	vector<long long> dp_prev(w+1, 0), dp(w+1, 0);
	vector<int> wi(n), vi(n);

	for(int i = 0; i < n; ++i){
		cin>>wi[i]>>vi[i];
	}

	for(int i = 0; i < n; ++i){
		for(int j = wi[i]; j <= w; ++j){
			dp[j] = max(dp_prev[j], vi[i] + dp_prev[j - wi[i]]);
		}
		dp_prev = dp;
	}

	cout<<dp_prev[w];

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)



int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;
	vector<int> a(n);
	vector<vector<int> > dp(n, vector<int>(n, 0));
	vector<int> dp2(n+1, 1e9);

	for(int i = 0; i  <n ;  ++i){
		cin>>a[i];
		dp[i][i] = a[i];
	}

	for(int l = 2; l <= n; ++l){
		for(int i = 0; i <= n-l; ++i){
			int j = i + l - 1;
			dp[i][j] = -1;
			for(int k = i; k < j; ++k){
				if(~dp[i][k] && dp[i][k] == dp[k+1][j]) dp[i][j] = dp[i][k] + 1;
			}
		}
	}

	dp2[0] = 0;
	for(int l = 1; l <= n; ++l){
		for(int i = 0; i < l; ++i){
			if(~dp[i][l-1]) dp2[l] = min(dp2[l], dp2[i] + 1); // equivalent to dp[i][l-1] != -1
		}
	}

	cout<<dp2[n];

	return 0;
}
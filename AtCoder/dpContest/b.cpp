#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int n, k;
	cin>>n>>k;

	vector<int> A(n), dp(n, INT_MAX);
	for(int i = 0; i < n; ++i) cin>>A[i];
	
	dp[0] = 0;
	for(int i = 1; i < n; ++i){
		for(int j = max(0, i-k); j < i; ++j){
			dp[i] = min(dp[i], abs(A[i] - A[j]) + dp[j]);
		}
	} 

	cout<<dp[n-1];

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;

	int A[n], dp[n] = {0};
	for(int i = 0; i < n; ++i) cin>>A[i];

	dp[1] = abs(A[1] - A[0]);
	
	for(int i = 2; i < n; ++i) dp[i] = min(abs(A[i] - A[i-1]) + dp[i-1], abs(A[i] - A[i-2]) + dp[i-2]);

	cout<<dp[n-1];

  return 0;
}
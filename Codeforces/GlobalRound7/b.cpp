#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////


	long long maxi;
	int n;
	cin>>n;
	vector<long long> A(n);
	for(int i = 0; i <  n; ++i) cin>>A[i];

	maxi = A[0];
	cout<<maxi;

	for(int i = 1; i < n; ++i){
		cout<<" "<<A[i] + maxi;
		maxi = max(maxi, A[i] + maxi);
	}

  return 0;
}
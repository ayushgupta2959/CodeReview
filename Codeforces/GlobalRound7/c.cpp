#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////
	long long n, k;
	cin>>n>>k;
	vector<int> A(n);
	long long x = n - k;
	int fi = -1;
	int i;
	int p = 998244353;
	long long result1 = (n*(n+1) - x*(x+1))/2;
	long long result2 = 1;
	for(i = 0; i<n; ++i) cin>>A[i];

	for(i = 0; i<n; ++i) {
		if(A[i] > x){
			fi = i;
		 	break;
		}
	}

	for(i = fi+1; i < n; ++i){
		if(A[i] > x){
			result2 = (result2*(i-fi))%p;
			fi = i;
		}
	}

	cout<<result1<<" "<<result2;
  	return 0;
}
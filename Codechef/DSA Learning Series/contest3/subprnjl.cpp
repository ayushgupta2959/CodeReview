#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long

int mxN = 2002;
vector<int> A(mxN); 
vector<ll> freq(mxN);

void solve(){
	int n, k;
	cin>>n>>k;
	for(int i = 0; i < n; ++i) cin>>A[i];

	int m;

	// for(int i = 0; i < mxN; ++i) freq[i] = 0;

	for(int l = 0; l < n ; ++l){
		for(auto& x: freq) x = 0;
		for(int r = l; r < n; ++r){
			m = ceil(k/())	
		}
		


	}


}

int main() {
	sp;

	////////////////To Remove//////////////
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}
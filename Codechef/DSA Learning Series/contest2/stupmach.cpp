#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	int n, x;
	long long sum = 0;
	int mn = 2e9;
	cin>>n;
	while(n--){
		cin>>x;
		mn = min(mn, x);
		sum += mn;
	}
	cout<<sum;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
void solve(){
	int n;
	cin>>n;
	vector<long long> a(n), b(n), health_left(n);
	for(int i = 0; i < n; ++i){
		cin>>a[i]>>b[i];
	}

	health_left[0] = max(0ll, a[0]-b[n-1]);
	long long sum = health_left[0];

	for(int i = 1; i < n; ++i){
		health_left[i] = max(0ll, a[i]-b[i-1]);
		sum += health_left[i];
	}
	// for(auto& x: health_left) cout<<x<<" ";
	// cout<<"\n";
	// cout<<sum<<"\n";
	long long min_bullets = 1ll*4e17;
	for(int i = 0; i < n; ++i){
		min_bullets = min(min_bullets, sum-health_left[i]+a[i]);
	}
	cout<<min_bullets;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}
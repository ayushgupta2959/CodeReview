#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(auto& y: a) cin>>y;

	sort(a.rbegin(), a.rend());

	int i = 0;
	int res_count = 0;
	long long sum = 0;
	while(i < n && a[i] >= x){
		sum += (a[i]-x);
		res_count++;
		i++;
	}
	while(i < n){
		if(x-a[i] <= sum){
			sum -= (x-a[i]);
			res_count++;
		}
		else break;
		i++;
	}
	cout<<res_count;
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
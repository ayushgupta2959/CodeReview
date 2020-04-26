#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto& x: a) cin>>x;
	sort(a.rbegin(), a.rend());
	for(auto& x: a) cout<<x<<" "; 
}
int main() {
	sp;

	////////////////To Remove//////////////
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  return 0;
}
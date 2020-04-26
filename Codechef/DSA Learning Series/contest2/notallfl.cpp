#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	for(auto& x: a) cin>>x;

	vector<int> flavours(k+1, 0);

	int distinct = 0;
	int res = 0;

	int l = 0, h = 0;
	while(h < n){
		if(flavours[a[h]] == 0) distinct++;
		flavours[a[h]]++;
		while(distinct == k){
			flavours[a[l]]--;
			if(flavours[a[l]] == 0) distinct--;
			l++;
		}
		res = max(res, h-l+1);
		h++;
	}
	cout<<res;
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
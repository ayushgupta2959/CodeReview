#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	string s;
	cin>>s;
	int n = s.size();
	int sum = 0;
	int res = 0;
	for(int i = 0; i < n; ++i){
		sum += (s[i] == '<') ? 1 : -1;
		if(sum < 0) break;
		if(sum == 0) res = i+1;
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
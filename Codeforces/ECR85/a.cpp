#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	int n;
	cin>>n;
	int prev_p, prev_c, cur_p, cur_c;
	cin>>prev_p>>prev_c;
	bool res = (prev_p >= prev_c);
	for(int i = 1; i < n; ++i){
		cin>>cur_p>>cur_c;
		if((cur_c >= prev_c) && (cur_p >= prev_p) &&(cur_p-prev_p >= cur_c-prev_c)){
			prev_c = cur_c;
			prev_p = cur_p;
		}
		else res = false;
	}
	if(res)cout<<"YES";
	else cout<<"NO";
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
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

bool solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto& x:a) cin>>x;

	int prev = -6;

	for(int i = 0; i < n; ++i){
		if(a[i]){
			if(i-prev < 6) return false;
			prev = i;
		}
	}
	return true;

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
		if(solve()) cout<<"YES";
		else cout<<"NO";
		cout<<"\n";
	}

  	return 0;
}
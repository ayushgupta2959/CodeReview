#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
void solve(){
	int n;
	cin>>n;
	int result = 0;
	while(n){
		result = result*10 + n%10;
		n /=10;
	}
	cout<<result;
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
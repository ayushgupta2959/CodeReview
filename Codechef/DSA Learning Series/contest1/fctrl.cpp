#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	long long five, res, n;
	cin>>t;
	while(t--){
		cin>>n;
		five = 5;
		res = 0;
		while(five <= n){
			res += n/five;
			five *= 5ll;
		}
		cout<<res;
		cout<<"\n";
	}

  	return 0;
}
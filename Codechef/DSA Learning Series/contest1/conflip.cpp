#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t, g, n, i, q;
	cin>>t;
	while(t--){
		cin>>g;
		while(g--){
			cin>>i>>n>>q;
			if(n&1) (i^q) ? (cout<<(n-(n>>1))) : (cout<<(n>>1));
			else cout<<(n>>1);
			cout<<"\n";
		}
	}

  	return 0;
}
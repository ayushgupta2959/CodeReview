#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define NL cout<<"\n";
#define test cerr<<"abcd\n";

int main() {
	sp;

	// ////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// ///////////////////////////////////////
	int t, n, x;
	int result;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>x;
		result = x;
		for(int i = 1; i < n; ++i){
			cin>>x;
			result = min(x, result);
		}
		cout<<result<<'\n';
	}

  	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define NL cout<<"\n";
#define test cerr<<"abcd\n";

int diff, i, ways;

void solve(int x, int y){
	ways = 0;
	if(x == y) ways = -1;
	diff = abs(x - y);
	for(i = 1; i*i < diff; ++i){
		if(diff % i == 0) ways+= 2;
	}
	if(i*i == diff) ways += 1;
}

int main() {
	sp;

	// ////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// ///////////////////////////////////////

	int t, a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		solve(a-1,b-1);
		cout<<ways<<'\n';
	}

  	return 0;
}
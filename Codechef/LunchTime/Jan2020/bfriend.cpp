#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ss stringstream
#define gl getline(cin, line)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	string line;

	int t, n;
	long long a, b, c, x, best;
	bool in_between;
	long long cost;

	gl;
	ss(line)>>t;

	while(t--){
		gl;
		ss(line)>>n>>a>>b>>c;
		cost = abs(a - b) + c;
		in_between = false;
		best = 1e9+5;
		if(a < b) swap(a, b);
		gl;
		ss(line)>>x;
		if(x >= b && x <= a) in_between = true;
		best = min(best,min(abs(a-x), abs(b-x)));
		n--;
		while(!in_between && n--){
			ss(line)>>x;
		    if(x >= b && x <= a) in_between = true;
		    best = min(best,min(abs(a-x), abs(b-x)));
		}
		if(!in_between){
			cost += 2LL*best;
		}
		cout<<cost<<'\n';
	}
  return 0;
}
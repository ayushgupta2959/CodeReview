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

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin>>a[i];

	unordered_map<int,long long> m;
	
	for(auto x: a) m[x]++;

	long long tr = 0;

	for(auto x: m){
		tr += (x.second >= 2)?((x.second)*(x.second-1))/2 : 0;
	}

	long long temp;
	for(auto x: a){
		if(m[x] >= 2){
			temp = tr - (m[x]*(m[x]-1))/2;
			temp += (m[x]-1 >= 2)?((m[x]-1)*(m[x]-2))/2 : 0;
			cout<<temp<<"\n";
		}
		else{
			cout<<tr<<"\n";
		}
	}

  return 0;
}
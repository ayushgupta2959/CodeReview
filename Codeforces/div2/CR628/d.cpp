#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	freopen("../../../input.txt", "r", stdin);
	freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	long long u, v;
	cin>>u>>v;

	if((u > v) || ((u&1) != (v&1))){
		cout<<-1;
		return 0;
	}
	if(u == v){
		if(u != 0) cout<<1<<"\n"<<u;
		else cout<<0;
		return 0;
	}
	long long x = (v - u)/2;
	if(x&u){
		cout<<3<<"\n"<<u<<" "<<x<<" "<<x;
	}
	else{
		cout<<2<<"\n"<<(x+u)<<" "<<x;
	}
  	return 0;
}
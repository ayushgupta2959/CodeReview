#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	ll n, res = 0;

	cin>>n;
	vector<int> a(n);
	for(auto& x: a) cin>>x;

	sort(a.begin(), a.end());

	for(auto& x: a){
		res = max(res, n*x);
		n--;
	}

	cout<<res;

  	return 0;
}
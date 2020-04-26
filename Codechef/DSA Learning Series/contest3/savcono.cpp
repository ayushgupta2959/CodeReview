#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	int n, z;
	cin>>n>>z;
	vector<int> a(n);

	for(auto& x: a) cin>>x;

	priority_queue<int> pq(a.begin(), a.end());
	int res = 0;
	int t;
	while(z > 0 && pq.size()){
		t = pq.top();
		pq.pop();
		z -= t;
		t >>= 1;
		if(t) pq.push(t);
		res++;
	}
	if(z > 0) cout<<"Evacuate";
	else cout<<res;
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
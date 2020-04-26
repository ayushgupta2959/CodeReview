#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define pi pair<int,int>
#define FF first
#define SS second
#define EB emplace_back

int main() {
	sp;

	//////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n, m, x;
	cin>>n>>m;
	vector<pi> a(n);
	vector<pi> b(m);

	for(int i = 0; i < n; ++i){
		cin>>x;
		a[i] = {x, i};
	}
	for(int i = 0; i < m; ++i){
		cin>>x;
		b[i] = {x, i};
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(int i = 0; i < n; ++i){
		cout<<a[i].SS<<" "<<b[0].SS<<"\n";
	}

	for(int i = 1; i < m; ++i){
		cout<<a[n-1].SS<<" "<<b[i].SS<<"\n";
	}

  	return 0;
}
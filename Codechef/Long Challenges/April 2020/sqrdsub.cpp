#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

void solve(){
	long long n;
	cin>>n;
	vector<int> a(n);
	for(auto& x: a) cin>>x;

	vector<int> f(n, 0);
	int count = 0;
	for(int i = 0; i < n; ++i){
		count = 0;
		while((a[i]) && (a[i]%2 == 0)){
			count++;
			a[i] /= 2;
		}
		f[i] = count;
	}

	unordered_map<int,int> m;
	m[0] = -1;
	long long csum = 0;
	long long result = (n*(n+1))/2;

	for(int i = 0; i < n; ++i){
		csum += f[i];
		if(f[i]){
			if(m.find(csum -1) != m.end()){
				result -= (i - m[csum-1]);
			}
			m[csum] = i;
		}
		else{
			if(m.find(csum - 1) != m.end()){
				result -= (m[csum] - m[csum-1]);
			}
		}
	}
	cout<<result;
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
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

bool solve_helper(vector<long long> &A, int n, int k){
	v(bool) is_set(60, false);
	int j, rem;
	for(int i = 0; i < n; ++i){
		j = 0;
		while(A[i]){
			rem = A[i]%k;
			if(rem >= 2) return false;
			if(rem == 1){
				if(is_set[j]) return false;
				else is_set[j] = true;
			}
			A[i] /= k;
			j++;
		}
	}
	return true;
}

void solve(){
	int n, k;
	cin>>n>>k;
	v(long long) a(n);
	for(auto& x: a) cin>>x;

	if(solve_helper(a, n, k)) cout<<"YES";
	else cout<<"NO";
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////


	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))
typedef long long ll;

int mex(vector<int> a){
	sort(a.begin(), a.end());
	a.resize(distance(a.begin(), unique(a.begin(), a.end())));
	for(int i = 0; i < a.size(); i++){
		if(a[i]^i) return i;
	}
	return a.size();
}

int get_index(long long x, int MOD){
	if(x > MOD){
		x = (x - 200)%MOD + 200;
	}
	return x;
}


void solve(){
	int n, x, y, z;
	cin>>n>>x>>y>>z;

	v(ll) a(n);
	int MOD=-1;
	for(auto& x: a) cin>>x;

	vv(int) sp = vvn(int, 500, 3, 0);
	// 0 => grundy value of n;
	// 1 => grundy value of n given last move is not y
	// 2 => grundy value of n given last move is not z 

	for(int i = 1; i < 500; ++i){
		sp[i][0] = mex({sp[max(i-x, 0)][0], sp[max(i-y, 0)][1], sp[max(i-z, 0)][2]});
		sp[i][1] = mex({sp[max(i-x, 0)][0], sp[max(i-z, 0)][2]});
		sp[i][2] = mex({sp[max(i-x, 0)][0], sp[max(i-y, 0)][1]});
		bool ok = false;
		if(i > 200 && MOD == -1){
			ok = true;
			for(int k = 0; k < 5; ++k){
				ok &= ((sp[i-k][0]==sp[200-k][0])&&(sp[i-k][1]==sp[200-k][1])&&(sp[i-k][2]==sp[200-k][2]));
			}
		}
		if(ok){
			MOD = i;
			// break;
		}
	}
	MOD -= 200;
	// cout<<MOD<<"\n";
	// for(int i = 0; i < 50; ++i){
	// 	cout<<i<<": "<<sp[i][0]<<" "<<sp[i][1]<<" "<<sp[i][2]<<"\n";
	// }

	long long xor_sum=0;
	
	for(auto& val:a){
		xor_sum ^= sp[get_index(val, MOD)][0];
	}

	if(!xor_sum){
		cout<<0;
		return;
	}

	int moves = 0;
	for(auto& val: a){
		int i = get_index(val, MOD);
		xor_sum ^= sp[i][0];
		xor_sum ^= sp[max(i-x, 0)][0];
		if(!xor_sum) moves++;
		xor_sum ^= sp[max(i-x, 0)][0];
		xor_sum ^= sp[max(i-y, 0)][1];
		if(!xor_sum) moves++;
		xor_sum ^= sp[max(i-y, 0)][1];
		xor_sum ^= sp[max(i-z, 0)][2];
		if(!xor_sum) moves++;
		xor_sum ^= sp[max(i-z, 0)][2];
		xor_sum ^= sp[i][0];
	}
	cout<<moves;
}


int main() {
	fast;

	////////////////To Remove//////////////
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////


	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}
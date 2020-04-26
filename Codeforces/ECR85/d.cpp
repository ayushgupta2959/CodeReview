#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

typedef long long ll;

bool do_overlap(int l1, int r1,int l2,int r2){
	if(r1 < l2 || l1 > r2) return false;
	else return true;
}

void solve(){
	ll n, l, r;
	cin>>n>>l>>r;
	ll s = 1;
	ll cur_left = 1;
	ll cur_right = 2*(n-s); 
	ll limit = n*(n-1); 
	cout<<limit<<"\n";
	while(cur_left <= limit){
		cout<<cur_left<<"\n";
		if(do_overlap(cur_left, cur_right, l, r)){
			int d = (l - cur_left)/2;
			for(int i = s, j = s+d+1; l <= r; ){
				if(l&1) cout<<i<<" ";
				else{
					cout<<j<<" ";
					if(j == n){
						i++;
						j = i+1;
					}
					else j++;
				}
				l++;
			}
			break;
		}
		else{
			s++;
			cur_left = cur_right + 1;
			cur_right +=  2*(n-s);
		}
	}
	if(l == r) cout<<1;
}
int main() {
	sp;

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
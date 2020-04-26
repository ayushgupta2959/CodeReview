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
	cin>>n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());

	int l1, l2;
	l2 = b[n-1];
	for(int i = n-1; i > 0; i--){
		if(b[i]-b[i-1] == 0){
			l1 = b[i];
			if((i+1)/2 != b[i] || i%2==0){
				cout<<0;
				return;
			}
			else break;
		}
		else if(b[i]-b[i-1] != 1){
			cout<<0;
			return;
		}
	}

	b = a;
	sort(b.begin(), b.begin()+l1);
	bool invalid = false;
	if(b[0] != 1){
		cout<<0;
		return;
	}
	for(int i = 1; i < l1; ++i){
		if(b[i]-b[i-1] != 1){
			cout<<0;
			return;
		}
	}
	int result = 1;
	sort(b.begin(), b.begin()+l2);
	for(int i = 1; i < l1; ++i){
		if(b[i]-b[i-1] != 1){
			invalid = true;
			break;
		}
	}
	if(!invalid) result = 2;
	if(result == 1){
		cout<<result<<"\n";
		cout<<
	}
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

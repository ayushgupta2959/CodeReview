#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	int n;
	cin>>n;
	
	string s;
	cin>>s;

	int l = s.size();

	int res = 0;
	int wina = 0, winb = 0;

	for(int i = 0; i < l; ++i){
		if(s[i] == '1'){
			if(i&1) winb++;
			else wina++;
		}
		if(i&1){
			if((winb + (n-i/2-1) < wina) || (wina + (n-i/2-1) < winb)){
				cout<<i+1;
				return;
			}
		}
		else{
			if((wina + (n-i/2-1) < winb)||(winb + (n-i/2) < wina)){
				cout<<i+1;
				return;
			}
		}
	}
	cout<<l;
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
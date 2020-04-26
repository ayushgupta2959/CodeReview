#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	vector<string> a(9);
	for(int i = 0; i < 9; ++i){
		cin>>a[i];
	}
	// for(int i = 0; i < 9; ++i){
	// 	for(int j = 0; j < 9; ++j){
	// 		cout<<a[i][j];
	// 	}
	// 	cout<<"\n";
	// }
	int i = 0;
	int j = 0;
	while(i < 9){
		if(a[i][j] != '1') a[i][j] = '1';
		else a[i][j] = '2';
		i++;
		j+=3;
		if(j >= 9) j = (j+1)%9;
	}
	for(int i = 0; i < 9; ++i){
		cout<<a[i]<<"\n";
	}
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
	}

  	return 0;
}
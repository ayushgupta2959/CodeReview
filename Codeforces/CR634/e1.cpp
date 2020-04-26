#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define EB emplace_back


void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto& x: a)cin>>x;
	int res = 0;
	vector<vector<int>> sum(27, vector<int>(n, 0));
	vector<vector<int>> occur(27, vector<int>());

	sum[a[0]][0] = 1;
	occur[a[0]].EB(0);

	for(int j = 1; j < n; ++j){
		for(int i = 1; i <= 26; ++i){
			sum[i][j] = sum[i][j-1];
			if(a[j] == i){
				sum[i][j] += 1;
				occur[i].EB(j);
			}
		}
	}


	// for(int i = 1; i <= 26; ++i){
	// 	for(int j = 0; j < occur[i].size(); ++j){
	// 		cout<<occur[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	for(int i = 1; i <= 26; ++i){
		if(occur[i].size() == 0) continue;

		res = max(res, (int)occur[i].size());
		int cur_occur;
		int js, je;
		js = 0, je = occur[i].size() - 1;
		while(js < je){
			for(int k = 1; k <= 26; ++k){
				if(i==k) continue;
				// cout<<occur[i][je]<<" "<<occur[i][js]<<"\n";
				cur_occur = sum[k][occur[i][je]];
				cur_occur -= sum[k][occur[i][js]];
				res = max(res, (js+1)*2 + cur_occur);
			}
			js++;
			je--;
		}
	}
	cout<<res;
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
		cout<<"\n";
	}

  	return 0;
}
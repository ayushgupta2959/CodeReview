#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define NL cout<<"\n";
#define test cerr<<"abcd\n";

int ur, br, lc, rc, n, m, result, maxl;

void update_result(vector<vector<int> > &A, int& row_index, int& col_index){
	ur = row_index - 1;
	br = row_index + 1;
	lc = col_index - 1;
	rc = col_index + 1;
	while((ur >= 0) && (br < n) && (lc >=0) && (rc < m) && (A[row_index][lc] == A[row_index][rc]) && (A[ur][col_index] == A[br][col_index])){
		result++;
		ur--;
		br++;
		lc--;
		rc++;
	}
}

void solve(vector<vector<int> > &A){
	result = n*m;
	maxl = min(n,m);
	int i, j;
	for(i=1;i<n;++i){
		for(j=1;j<m;++j){
			update_result(A, i, j);
		}
	}
}
int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int t, i, j;
	cin>>t;
	vector<vector<int> > A;
	while(t--){
		cin>>n>>m;
		A.resize(n, vector<int>(m));
		for(i = 0; i < n; ++i){
			for(j = 0; j < m; ++j){
				cin>>A[i][j];
			}
		}
		solve(A);
		cout<<result<<"\n";
		A.clear();
	}
  return 0;
}
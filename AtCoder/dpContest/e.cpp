// #include <bits/stdc++.h>
// using namespace std;

// #define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

// int solve(int W, int i, vector<pair<int,int> > &v, map<pair<int,int>, long long> &m){
// 	if((i < 0) || (W < v[i].first)) return 0;

// 	if(m.find({i, W}) == m.end()){
// 		long long val = max(
// 			solve(W - v[i].first, i - 1, v, m) + v[i].second,
// 			solve(W, i - 1, v, m)
// 		);
// 		m[{i, W}] = val;
// 	}
// 	return m[{i, W}];
// }

// int main() {
// 	sp;

// 	////////////////To Remove//////////////
// 	// freopen("input.txt", "r", stdin);
// 	// freopen("output.txt", "w", stdout);
// 	///////////////////////////////////////

// 	int n, w;

// 	cin>>n>>w;

// 	vector<pair<int, int> > v(n);

// 	for(int i = 0; i < n; ++i){
// 		cin>>v[i].first>>v[i].second;
// 	}

// 	sort(v.rbegin(), v.rend());

// 	map<pair<int,int>, long long> m;

// 	cout<<solve(w, n - 1, v, m);

//   return 0;
// }



// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

#define V_SUM_MAX 1000 
#define N_MAX 100 
#define W_MAX 10000000 

// To store the states of DP 
int dp[V_SUM_MAX + 1][N_MAX]; 
bool v[V_SUM_MAX + 1][N_MAX]; 

// Function to solve the recurrence relation 
int solveDp(int r, int i, int* w, int* val, int n) 
{ 
	// Base cases 
	if (r <= 0) 
		return 0; 
	if (i == n) 
		return W_MAX; 
	if (v[r][i]) 
		return dp[r][i]; 

	// Marking state as solved 
	v[r][i] = 1; 

	// Recurrence relation 
	dp[r][i] 
		= min(solveDp(r, i + 1, w, val, n), 
			w[i] + solveDp(r - val[i], 
							i + 1, w, val, n)); 
	return dp[r][i]; 
} 

// Function to return the maximum weight 
int maxWeight(int* w, int* val, int n, int c) 
{ 

	// Iterating through all possible values 
	// to find the the largest value that can 
	// be represented by the given weights 
	for (int i = V_SUM_MAX; i >= 0; i--) { 
		if (solveDp(i, 0, w, val, n) <= c) { 
			return i; 
		} 
	} 
	return 0; 
} 

// Driver code 
int main() 
{ 
	int w[] = { 6, 5, 6, 6, 3, 7 }; 
	int val[] = { 5, 6, 4, 6, 5, 2 }; 
	int n = sizeof(w) / sizeof(int); 
	int C = 15; 

	cout << maxWeight(w, val, n, C)<<"\n"; 

	for(int i = 0; i <= 20; ++i){
		for(int j = 0; j <= n; ++j){
			printf("%10d", dp[i][j]);
		}
		cout<<"\n";
	}

	return 0; 
} 

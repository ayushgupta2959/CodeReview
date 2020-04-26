#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;


int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n, k;
	ll p = 1e9+7;
	cin>>n>>k;
	vector<int> a(n);

	for(auto& x: a) cin>>x;

	vector<int> smaller_index(n, -1);

	stack<int> st;
	for(int i = 0; i < n; ++i){
		while(!st.empty() && a[st.top()] > a[i]){
			smaller_index[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	ll res = 1;
	for(int i = 0; i < n; ++i){
		if(smaller_index[i] == -1) continue;
		res = (res*(smaller_index[i] - i + 1))%p;
	}

	cout<<res;

  	return 0;
}
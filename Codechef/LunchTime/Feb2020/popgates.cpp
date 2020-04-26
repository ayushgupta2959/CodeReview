#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define NL cout<<"\n";
#define test cerr<<"abcd\n";

int t, n, k, i;
bool state;
int result_heads;

void get_heads(vector<bool> &A){
	state = false;
	for(i = n - 1; i >= (n-k); i--){
		if(A[i] != state) state = !state;
	}

	result_heads = 0;
	for(;i >=0; i--){
		if(A[i]) result_heads++;
	}
	if(state) result_heads = n-k-result_heads;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	char c;
	vector<bool> A(105); // Head => true, Tail => false
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(i = 0; i < n; ++i) {
			cin>>c;
			if(c == 'H') A[i] = true;
			else A[i] = false;
		}
		get_heads(A);
		cout<<result_heads<<'\n';
	}
  return 0;
}
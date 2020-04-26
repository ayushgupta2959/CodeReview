#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define NL cout<<"\n";
#define test cerr<<"abcd\n";

#define maxlen 200005

int main() {
	sp;

	////////////////To Remove//////////////
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	vector<int> A(maxlen);
	vector<int> left_sum(maxlen);
	vector<int> right_sum(maxlen);

	int t, n, i, ;
	while(t--){
		cin>>n;
		for(i = 0; i < n; ++i) cin>>A[i];
		left_sum[0] = A[0];
		for(i = 1; i < n; ++i) left_sum[i] = left_sum[i-1] + A[i];
		right_sum[n-1] = [n-1];
		for(i = n-2; i >=0 ;--i) right_sum[i] = right_sum[i+1] + A[i];

		for(i = 0; i < n; ++i){

		} 
	}

  	return 0;
}
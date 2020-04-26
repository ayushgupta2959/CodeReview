#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	long long n, m;
	cin>>n>>m;
	long long result = ((n>=2)?(n)*(n-1)/2:0) + ((m>=2)?(m)*(m-1)/2:0);
	cout<<result;
  return 0;
}
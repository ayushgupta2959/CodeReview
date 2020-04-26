#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;
	int max_nesting_level = 0;
	int start_nesting_level = -1;
	int max_symbols = 0;
	int start_max_symbols = -1;
	int start = 0;
	int x;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin>>x;
		if(x == 1){
			if(sum == 0){
				start = i;
			}
			sum++;
		}
		else{
			sum--;
			if((sum == 0) && (i-start+1 > max_symbols)){
				max_symbols = i-start+1;
				start_max_symbols = start+1;
			}
		}
		if(sum > max_nesting_level){
			max_nesting_level = sum;
			start_nesting_level = i+1;
		}
	}
	cout<<max_nesting_level<<" "<<start_nesting_level<<" "<<max_symbols<<" "<<start_max_symbols;

  	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define pi pair<int, int>
#define FF first
#define SS second


int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n, qn;
	cin>>n>>qn;
	vector<int> a(n);

	for(auto& x: a) cin>>x;

	int l = 0;
	int h = 1;
	set<pi> s;

	while(h < n){
		if(a[h] % a[h-1]){
			s.insert({l, h-1});
			l = h;
		}
		h++;
	}
	s.insert({l, n-1});

	int q_type, i, x;  
	pi cur_range, prev_range, next_range;
	auto it = s.begin();
	while(qn--){
		cin>>q_type;
		if(q_type == 1){
			cin>>i>>x;
			i--; // converrting to zero based indexing
			a[i] = x;

			it = prev(s.lower_bound({i, INT_MAX}));
			cur_range = *it;

			if(i == 0){;}
			else if((a[i] % a[i-1]) &&(cur_range.FF < i)){ //  not divisible and i-1 in cur range then partition
				s.erase(it);					// erase current range
				s.insert({cur_range.FF, i-1}); // insert two ranges after partitioning
				s.insert({i, cur_range.SS});
			}
			else if((a[i] % a[i-1] == 0) &&(cur_range.FF == i)){ // if divisible and i-1 not in cur range then merge cur and prev range
				auto prev_it = prev(it); // get prev range iterator
				prev_range = *prev_it;  // get prev range
				s.erase(it); // erase cur_range
				s.erase(prev_it); // erase prev_range
				s.insert({prev_range.FF, cur_range.SS}); // insert merged range
			}

			it = prev(s.lower_bound({i, INT_MAX})); // resetting ranges due to  changes in above steps
			cur_range = *it;

			if(i == n-1){;}
			else if(a[i+1] % a[i] && i < cur_range.SS){ // not divisible and i+1 in cur_range
				s.erase(it); // erase cur range 
				s.insert({cur_range.FF, i}); // insert two new ranges
				s.insert({i+1, cur_range.SS});
			}
			else if((a[i+1] % a[i] == 0) &&(i == cur_range.SS)){ // divisible and i+1 not in cur_range
				auto next_it = next(it); // getting next range iterator
				next_range = *next_it; // getting next range
				s.erase(it); // erasing cur_range 
				s.erase(next_it); // erasing next range
				s.insert({cur_range.FF, next_range.SS}); // insert merged range 
			}
		}
		else{
			cin>>i;
			i--;
			cur_range = *prev(s.lower_bound({i, INT_MAX}));
			cout<<cur_range.FF+1<<"\n";
		}
	}

  	return 0;
}
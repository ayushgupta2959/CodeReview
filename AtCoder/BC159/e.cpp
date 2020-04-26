#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define eb emplace_back
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))
#define bc(x) __builtin_popcountll(x)


v(int) get_row_groups(int b, int h){
	v(int) row_groups = {0};
	for(int i = 0; i < h; i++){
		if(b&1) row_groups.eb(i+1);
		b >>= 1;
	}
	row_groups.eb(h);
	return row_groups;
}

bool sum_col_ok(v(string)& a, v(int)& row_groups, int ci, v(int)& col_sum, int limit){
	int gs = row_groups.size();
	for(int i = 0; i < gs-1; ++i){
		for(int ri = row_groups[i]; ri < row_groups[i+1]; ri++){
			if(a[ri][ci] & 1){
				col_sum[i] += 1;
			}
			if(col_sum[i] > limit) return false;
		}
	}
	return true;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int h,w,k;
	cin>>h>>w>>k;

	v(string) a(h);

	for(int i=0; i < h; ++i) cin>>a[i];

	int h_split_ways = 1<<(h-1);

	int min_lines = 1e9;
	int current_lines;

	for(int i=0; i < h_split_ways; ++i){
		current_lines = bc(i);
		v(int) row_groups = get_row_groups(i, h);

		v(int) col_groups = {0};
		bool possible = true;
		v(int) col_sum(row_groups.size(), 0);
		for(int ci = 0; ci < w; ci++){
			if(!sum_col_ok(a, row_groups, ci, col_sum, k)){
				if(col_groups.back() == ci){
					possible = false;
					break;
				}
				col_groups.eb(ci);
				ci--;
				col_sum = vn(int, row_groups.size(), 0);
			}
		}
		if(possible){
			min_lines = min(min_lines, bc(i) + (int)col_groups.size() - 1);
		}
	}

	cout<<min_lines;

  	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define test cerr<<"abcd\n";

#define pi pair<int,int>
#define fi first
#define se second

vector<int> stf;
vector<int> sts;

bool f1,f2,f;
int newl, newr;
int lc(int p){return p<<1;}
int rc(int p){return (p<<1)|1;}

bool is_increasing_at_end(vector<int> &A,int x,int y){
  if(A[y] > A[y-1]) return true;
  else return false;
}

bool is_increasing_at_start(vector<int> &A,int x,int y){
  if(A[x] < A[x+1]) return true;
  else return false;
}

void build(int p,int l,int r,vector<int> &A){
  if(l==r){
    stf[p] = 0;
    sts[p] = 0;
    return;
  }
  int m = (l+r)/2;
  build(lc(p), l, m, A);
  build(rc(p), m+1, r, A);
  if(l != m && (m+1)!= r){
    f1 = is_increasing_at_end(A, l, m);
    f2 = is_increasing_at_start(A, m+1, r);
    if(f1 && f2){
      if(A[m] < A[m+1]){
        stf[p] = stf[lc(p)] + stf[rc(p)] - 1;
        sts[p] = sts[lc(p)] + sts[rc(p)];
      }
      else{
        stf[p] = stf[lc(p)] + stf[rc(p)];
        sts[p] = sts[lc(p)] + sts[rc(p)] + 1;
      }
    }
    else if(!f1 && !f2){
      if(A[m] < A[m+1]){
        stf[p] = stf[lc(p)] + stf[rc(p)] + 1;
        sts[p] = sts[lc(p)] + sts[rc(p)];
      }
      else{
        stf[p] = stf[lc(p)] + stf[rc(p)];
        sts[p] = sts[lc(p)] + sts[rc(p)] - 1;
      }
    }
    else{
      stf[p] = stf[lc(p)] + stf[rc(p)];
      sts[p] = sts[lc(p)] + sts[rc(p)];
    }
  }
  else if(l == m && m+1 != r){
    f = is_increasing_at_start(A, m+1, r);
    if(f && (A[m+1] < A[m])){
      stf[p] = stf[lc(p)] + stf[rc(p)];
      sts[p] = sts[lc(p)] + sts[rc(p)] + 1;
    }
    else if(!f && (A[m+1] > A[m])){
      stf[p] = stf[lc(p)] + stf[rc(p)] + 1;
      sts[p] = sts[lc(p)] + sts[rc(p)];
    }
    else{
      stf[p] = stf[lc(p)] + stf[rc(p)];
      sts[p] = sts[lc(p)] + sts[rc(p)];
    }
  }
  else if(l != m && (m+1)== r){
    f = is_increasing_at_end(A, l, m);
    if(f && (A[m+1] < A[m])){
      stf[p] = stf[lc(p)] + stf[rc(p)];
      sts[p] = sts[lc(p)] + sts[rc(p)] + 1;
    }
    else if(!f && (A[m+1] > A[m])){
      stf[p] = stf[lc(p)] + stf[rc(p)] + 1;
      sts[p] = sts[lc(p)] + sts[rc(p)];
    }
    else{
      stf[p] = stf[lc(p)] + stf[rc(p)];
      sts[p] = sts[lc(p)] + sts[rc(p)];
    }
  }
  else{
    if(A[m] > A[m+1]){
        stf[p] = 0;
        sts[p] = 1;
    }
    else{
        stf[p] = 1;
        sts[p] = 0;
    }
  }
}

pi query(int p,int l,int r,int &ql,int &qr, vector<int> &A){
  if(r<ql || l>qr) return make_pair(0,0);
  if(l>=ql && r<=qr) return make_pair(stf[p],sts[p]);
  int m = (l+r)/2;
  pi q1 = query(lc(p),l,m,ql,qr,A);
  pi q2 = query(rc(p),m+1,r,ql,qr,A);
  pi result(q1.fi + q2.fi, q1.se + q2.se);
  if(m < ql || m+1 > qr) return result;
  newl = max(l, ql);
  newr = min(r, qr);
  if(newl != m && (m+1)!= newr){
    f1 = is_increasing_at_end(A, l, m);
    f2 = is_increasing_at_start(A, m+1, r);
    if(f1 && f2){
      if(A[m] < A[m+1]){
        result.fi -= 1;
      }
      else{
        result.se += 1;
      }
    }
    else if(!f1 && !f2){
      if(A[m] < A[m+1]){
        result.fi += 1;
      }
      else{
        result.se -= 1;
      }
    }
  }
  else if(newl == m && (m+1) != newr){
    f = is_increasing_at_start(A, m+1, r);
    if(f && (A[m+1] < A[m])){
      result.se += 1;
    }
    else if(!f && (A[m+1] > A[m])){
      result.fi += 1;
    }
  }
  else if(newl != m && (m+1) == newr){
    f = is_increasing_at_end(A, l, m);
    if(f && (A[m+1] < A[m])){
      result.se += 1;
    }
    else if(!f && (A[m+1] > A[m])){
      result.fi += 1;
    }
  }
  else{
    if(A[m] > A[m+1]) result.se += 1;
    else result.fi += 1;
  }
  return result;
}

int main() {
  sp;
  ///////////////To Remove//////////////////////
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  /////////////////////////////////////

  int n, q, l, r;
  cin>>n>>q;
  stf.clear();
  stf.resize(4*n,0);
  sts.clear();
  sts.resize(4*n,0);

  vector<int> A(n);
  for(int i = 0; i < n; ++i) cin>>A[i];
  build(1,0,n-1,A);
  
  pi result;

  //////testing////////////////////////////
  // cout<<"///////////////////////////\n\n";
  // for(int i=1; i<4*n;++i){
  //   cout<<i<<" - "<<stf[i]<<" "<<sts[i]<<"\n";
  // }
  // for(int i = 0; i < n; ++i){
  //   for(int j = i; j < n; ++j){
  //     result = query(1,0,n-1,i,j,A);
  //     cout<<"{"<<i<<","<<j<<"} -> {"<<result.fi<<","<<result.se<<"} ";
  //     if(result.fi == result.se) cout<<"YES\n";
  //     else cout<<"NO\n";
  //   }
  // }
  // cout<<"///////////////////////////\n\n";
  /////////////////////////////////////////

  for(int i = 0; i < q; ++i){
    cin>>l>>r;
    l--;
    r--;
    result = query(1,0,n-1,l,r,A);
    if(result.fi == result.se) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}

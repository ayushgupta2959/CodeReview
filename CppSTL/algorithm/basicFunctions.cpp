#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //functions to check for usage
    /*
    remove_if()
    revere_copy()
    lower_bound()
    merge()
    sort()
    min_element()
    */
    //next_permutation(range.begin(),range.end())
    int arr[4] = {1,2,3,4};
    int n = 4;
    do{
        for(int i=0;i<n;++i) cout<<arr[i]<<" ";
        cout<<"\n";
    }while(next_permutation(arr,arr+n));

    //accumulate(range.begin(),range.end(),initial_value_of_sum)
    int sum = accumulate(arr,arr+n,0);
    cout<<sum<<"\n";

    //min_element()
    cout<<*min_element(arr,arr+n)<<"\n";
    return 0;
}

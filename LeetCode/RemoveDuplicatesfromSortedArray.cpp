/*
O(nlgn)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 0;
        int i=0;
        int n = nums.size();
        while(i<n){
            unique++;
            i = upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
        }
        int j = 0;
        for(i=1;i<unique;++i){
            j = upper_bound(nums.begin(),nums.end(),nums[j])-nums.begin();
            nums[i]=nums[j];
        }
        return unique;
    }
};
*/
//optimized
//O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j,k;
        int n = nums.size();
        if(n==0) return 0;
        i=0,j=1,k=1;
        while(j<n){
            while(j<n && nums[i]==nums[j]) j++;
            if(j<n){
                nums[k]=nums[j];
                i=j;
                j++;
                k++;
            }
        }
        return k;
    }
};
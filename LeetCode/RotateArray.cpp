class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse_array(nums,0,n-1);
        reverse_array(nums,0,k-1);
        reverse_array(nums,k,n-1);
    }
    void reverse_array(vector<int> &nums,int s,int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
};
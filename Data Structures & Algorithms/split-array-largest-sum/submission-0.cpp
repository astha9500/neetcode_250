class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);

        while(l<=r){
            int mid = l+(r-l)/2;

            int sub=1;
            int cursum = 0;
            for(int i =0;i<nums.size();i++){
                if(cursum + nums[i] > mid){
                    sub++;
                    cursum = nums[i];
                }   
                else cursum += nums[i];
            }
            if(sub <= k) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
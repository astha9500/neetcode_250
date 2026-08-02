class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int load =0;
        int ans =0;

        while(l<=r){
            int mid = (l+r)/2;
            int load = weights[0];
            int daysu = 1;
            int sum =0;

            for(int i =1;i<weights.size();i++){
                if(load+weights[i] > mid){
                    daysu++;
                    load = weights[i];
                }
                else {
                    load += weights[i];
                }
            }
            if(daysu <= days){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;

        }
        return ans;
        
    }
};
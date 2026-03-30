class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;

        // Count frequency
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int maxFreq = 0;
        int ans = nums[0];

        for(auto it : mp) {
            if(it.second > maxFreq) {
                maxFreq = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxArea(vector<int>& heights) {
        unordered_map<int,int>mp;
        int res = 0;
        for(int i =0;i<heights.size();i++){
            for(int j=i+1;j<heights.size();j++){
           res = max(res,(j-i)*min(heights[i],heights[j]));
            }
        }
        return res;
        
    }
};

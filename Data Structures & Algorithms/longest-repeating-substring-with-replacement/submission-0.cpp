class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> cnt;
        int ans =0,l =0,maxfre=0;

        for(int r=0;r<s.size();r++){
            cnt[s[r]]++;

            maxfre = max(maxfre,cnt[s[r]]);

            while(r-l+1 - maxfre > k){
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
return ans;
        
    }
};

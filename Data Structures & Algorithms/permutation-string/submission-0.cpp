class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int l = 0 ;
        vector<int>fr1(26,0),fr2(26,0);
         for(int i =0;i<s1.size();i++){
            fr1[s1[i] - 'a']++;
         }
         for(int r =0;r<s2.size();r++){
            fr2[s2[r] - 'a']++;

            if(r-l+1 > s1.size()){
                fr2[s2[l]-'a']--;
                l++;
            }

            if(r-l+1 == s1.size()){
                if(fr1 == fr2) return true;
            }
         }
         return false;
    }
};

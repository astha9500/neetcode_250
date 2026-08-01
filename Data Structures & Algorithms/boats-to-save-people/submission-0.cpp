class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int l = 0,r=people.size()-1,cnt=0;

        while(l<=r){
            int rem = limit - people[r];
            r--;
            cnt++;
            if(l<=r && rem >= people[l]) l++;
        }
        return cnt;
    }
};
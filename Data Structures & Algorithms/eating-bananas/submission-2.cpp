class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,r=*max_element(piles.begin(),piles.end());

        while(l<=r){
            int hrs =0;
            int mid = (l+r)/2;
            for(int p:piles){
                hrs += ceil(double(p)/double(mid));
            }
            if(hrs <= h) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};

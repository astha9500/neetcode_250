class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;

        for(int i =0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        int l =1,r=maxi;

        while(l<=r){
            int k = l+(r-l)/2;

            long long hrs =0;

            for(int i=0;i<piles.size();i++){

                hrs+= ceil(double(piles[i])/double(k));
            }

            if(hrs<=h)   r = k-1;
            
            else l = k+1;
            
        }
          return l;
        
    }
};

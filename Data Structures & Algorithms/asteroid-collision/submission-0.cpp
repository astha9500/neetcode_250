class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
           
        for(int n: asteroids){
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && n < 0){
                     if(st.top() < abs(n)) st.pop();

                     else if(st.top() == abs(n)){
                        destroyed = true;
                        st.pop();
                        break;
                     }
                     else {
                        destroyed = true;
                        break;
                     }
                 }
                 if(!destroyed) st.push(n);
        }
        vector<int>ans(st.size());

       for(int i = st.size()-1 ; i>=0;i--){
        ans[i]= (st.top());
        st.pop();
       }
        return ans; 
    }
};
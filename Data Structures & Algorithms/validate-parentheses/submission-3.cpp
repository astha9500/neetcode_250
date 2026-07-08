class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        if(s.size()%2 != 0) return false;

        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else {
                if(st.empty()) return false;
            
            int top = st.top();
            st.pop();
            
            if((c == ')' && top != '(')
             ||( c== '}' && top!= '{' )
             || ( c == ']' && top != '['))
              return false;
            }
        }
        return st.empty();
        
    }
};

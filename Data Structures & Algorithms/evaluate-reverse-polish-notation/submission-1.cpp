class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>num;
        stack<string>op;

        for(string c : tokens){
            if(c== "+" || c == "-" || c == "*" || c =="/"){
                op.push(c);
            }
            else {
                num.push(stoi(c));
            }

            if(num.size() >= 2 && !op.empty()){
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                string ope = op.top();
                op.pop();

                if(ope == "+") num.push(b+a);
                else if(ope == "-") num.push(b-a);
                else if (ope == "*") num.push(b*a);
                else if(ope == "/")num.push(b/a);
            }
        }
        
        return num.top();
    }
};

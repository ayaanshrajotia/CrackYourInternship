class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token: tokens) {
            if (token == "+" or token == "-" or token == "*" or token == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                int num3;

                switch(token[0]) {
                    case '*':
                        num3  = num1 * num2;
                        break;
                    case '+':
                        num3 = num1 + num2;
                        break;
                    case '-':
                        num3 = num1 - num2;
                        break;  
                    case '/':
                        num3 = num1 / num2;
                        break;       
                }
                st.push(num3);
            } 
            else st.push(stoi(token));
            
        }
        return st.top();
    }
};
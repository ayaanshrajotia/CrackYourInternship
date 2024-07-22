//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        
        for (int i=0; i<S.size(); i++) {
            char ch = S[i];
            
            if (isdigit(ch)) {
                st.push(ch - '0');
            }
            else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                
                int num3;
                
                if (ch == '*') {
                    num3 = num1 * num2;
                }
                else if (ch == '+') {
                    num3 = num1 + num2;
                }
                else if (ch == '-') {
                    num3 = num1 - num2;
                }
                else if (ch == '/') {
                    num3 = num1 / num2;
                }
                st.push(num3);
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
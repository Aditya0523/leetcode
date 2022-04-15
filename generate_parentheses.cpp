// Here we see that there are choices that we can either select "(" or ")"
    // So this is a recursive problem ( an extended i/o method question )
    // OBSERVATIONS :  
    // The opening and closing will always be with "(" & ")" repectively.
    // Also you cannot choose to put a closing brace if it is balanced in-between. 
    // Count of open will reach zero before that of close
    // Choice of opening bracket is always 
    
    void solve(string output, int open, int close, vector<string>& ans)
    {
        // base case
        if(open == 0 && close == 0)
        {
            ans.push_back(output) ;
            return ;
        }
       // open is always available, until no more
        if(open != 0)
        {
            string op1 = output ;
            op1.push_back('(') ;
            
            solve(op1, open-1, close, ans) ;
        }
        
        if( close > open )
        {
            string op2 = output ;
            op2.push_back(')') ;
            
            solve(op2, open, close-1, ans) ;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open = n-1 ;
        int close = n ;
        
        string output = "(";
        vector<string> ans ;
        
        solve(output, open, close, ans) ;
        
        return ans ;
    }

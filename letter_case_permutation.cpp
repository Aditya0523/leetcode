 void solve(int i, string ip, string op, vector<string>& ans)
    {
        if(i == ip.length())    
        {
            ans.push_back(op) ;
            return ;
        }
 
         // if number
        if(ip[i] >= '0' && ip[i] <= '9')
        {
            op.push_back(ip[i]) ;
            solve(i+1, ip, op, ans) ;
        }
        else  // if character
        {
          if(islower(ip[i]))  
          {
              string op1 = op ;
              op1.push_back(ip[i]) ;
              solve(i+1, ip, op1, ans) ;
              
              string op2 = op ;
              op2.push_back(toupper(ip[i])) ;
              solve(i+1, ip, op2, ans) ;
          }
            else
            {
              string op1 = op ;
              op1.push_back(ip[i]) ;
              solve(i+1, ip, op1, ans) ;
              
              string op2 = op ;
              op2.push_back(tolower(ip[i])) ;
              solve(i+1, ip, op2, ans) ;
            }
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
       string output="" ;
        vector<string> ans ;
        int i=0 ;
        
        solve(i, s, output, ans) ;
        return ans ;
    }

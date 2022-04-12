void setCount(vector<vector<int>>& ans, int i, int j)
    {
        int r = ans.size() ;
        int c = ans[0].size() ;
        
       for(int x = i-1; x<=i+1; x++) 
       {
           for(int y=j-1; y<=j+1; y++)
           {
               if( x != i || y != j ) // do not change the  i,j th value
               {
                   // making sure indices are within bounds
                   if((x>=0 && x<r) && (y>=0 && y<c)) 
                       ans[x][y]++ ;
               }
           }
       }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        // setting up the count
        int r = board.size() ;
        int c = board[0].size() ;
        
        vector<vector<int>> ans(r, vector<int>(c, 0)) ;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(board[i][j] == 1)
                    setCount(ans, i, j) ;
            }
        }
        
        // final state
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                // cout<<ans[i][j]<<endl ;
                if(board[i][j])
                {
                    if(ans[i][j] < 2)
                        board[i][j] = 0 ;
                    else if(ans[i][j] == 2 || ans[i][j] == 3)
                        board[i][j] = 1 ;
                    else
                        board[i][j] = 0 ;
                }
                else
                {
                    if(ans[i][j] == 3)
                        board[i][j] = 1 ;
                    else
                        board[i][j] = 0 ;
                }
            }
        }
    }

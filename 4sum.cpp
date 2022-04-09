 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans ;
        sort(nums.begin(), nums.end()) ;
        
        if(nums.size() < 3)
            return ans ;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(i == 0 || ( i>0 && nums[i] != nums[i-1]))
            {
                for(int j=i+1; j<nums.size()-1; j++)
                {
                    if(j==i+1 || ( j>i+1 && nums[j] != nums[j-1]))
                    {
                        int lo = j+1 ;
                        int hi = nums.size()-1 ;
                        int sum = target - nums[j] - nums[i] ;
                        
                        while(lo < hi)
                        {
                            if(sum == nums[lo] + nums[hi])
                            {
                                vector<int> temp ;

                                temp.push_back(nums[i]) ;
                                temp.push_back(nums[j]) ;
                                temp.push_back(nums[lo]) ;
                                temp.push_back(nums[hi]) ;

                                ans.push_back(temp) ;

                                while(lo < hi && nums[lo] == nums[lo+1])
                                    lo++ ;
                                while(lo < hi && nums[hi] == nums[hi-1])
                                    hi-- ;
                                
                                lo++ ;
                                hi-- ;
                                    
                            }
                            else if(sum > nums[lo] + nums[hi])
                                lo++ ;
                            else
                                hi-- ;
                            
                        }
                    }
                }
            }
        }
        
        
        return ans ;
    }
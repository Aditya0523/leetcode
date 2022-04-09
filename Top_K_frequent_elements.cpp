/*** The main logic here is :

Store the frequency of elements of array in a map
But we need descending order of values in the key-value pair inside the map
So sort the map values in the descending order of value
Then put the keys of the first k elements in the answer array
FIRST APPROACH
***/
struct comp 
   {
	template <typename T>

	// Comparator function
	bool operator()(const T& l,
					const T& r) const
	{
		if (l.second != r.second) {
			return l.second > r.second;
		}
		return l.first > r.first;
	}
   };
    
    void sort(map<int, int>& M, vector<int>& ans, int k)
   {
	// creating a set of pairs (as a map contains key-value pair)
	// also using a comparator function to build the custom functionality
	set<pair<int, int>, comp> S(M.begin(),
								M.end());
      
	  // Iterate through the set and push the first k element into answer array
	  // pass by reference
     for(auto& it : S)
     {
         if(k > 0)
         {
            ans.push_back(it.first)  ;
         }
         k-- ;
     }
   }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq ;
        
		// storing frequency in the map
        for( int x : nums )
            freq[x]++ ;
        
        vector<int> ans ;
		// sorting the values
        sort(freq, ans, k) ;
        return ans ;
    }

/***
This can also be solved using a priority queue without having a comparator function
SECOND APPROACH
***/
vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int, int> freq ;
       for(auto x: nums)
           freq[x]++ ;
        
		// making a priority queue of pair
		// map stores key: value
		// Our priority queue will store => value : key
		
        priority_queue<pair<int, int>> pq ;
        for(auto x: freq)
            pq.push({x.second, x.first}) ;
        
        vector<int> ans ;
        
        while(k--)
        {
		// pushing the top elements second value ( which is key in the map )
            ans.push_back(pq.top().second) ;
			// pop the top element
            pq.pop() ;
        }
        
        return ans ;
    }
/***
Since normal map is sorted which increases the time complexity , but we are not using the map for anything except to store the frequency
So, an unordered map can be used instead for better optimization.

THIRD APPROACH
***/

vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> freq ;
       for(auto x: nums)
           freq[x]++ ;
        
        priority_queue<pair<int, int>> pq ;
        for(auto x: freq)
            pq.push({x.second, x.first}) ;
        
        vector<int> ans ;
        
        while(k--)
        {
            ans.push_back(pq.top().second) ;
            pq.pop() ;
        }
        
        return ans ;
    }
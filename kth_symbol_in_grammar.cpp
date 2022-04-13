 // OBSERVATIONS: 
    // 1. The problem itself is defined recursively so recursion is gonna be used.
    // 2. Since for each bit 2 bits are generated in next step, the length of any one step i is 2^i (0-indexed) .
    // 3. We observe that the grammar is transfered to the next one till the mid and then the values are all flipped.
    
    int kthGrammar(int n, int k) {
      // base case: given in the question as a test case.
        if(n == 1 && k == 1)
          return 0 ;
        
        //mid = length/2 ;; length = 2^(n-1)
        int mid = pow(2, n-1)/2 ;
        
        // Now to make recursive call, reduce both n and k.
        // n -> n-1 ... But for k there is an observation.
        
        // When the k lies within the mid, that means it is the same as the previous one. But if it lies ahead of mid it will be the flipped version of previous one
        if(k <= mid)
            return kthGrammar(n-1, k) ;
        else
            return !kthGrammar(n-1, k-mid) ;
    }

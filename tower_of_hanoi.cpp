// We see that the problem looks same whether the input disks are 64 or 3 or any other number.
// So, there is a hint of recursion
// Now the problem is recursive , here 
// We simply have to move the top n-1 disks to the helper rod ( which is a recursive call )
// then move the base disk to the destination rod
// then move the n-1 disks in the helper rod to the destination rod using the starter rod.
// ( which is a recursive call )

long long toh(int N, int from, int to, int aux) {
        
      if(N == 1)
      {
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n" ;
        return 1 ;
      }
    
        long long val = toh(N-1, from, aux, to) ;
        
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n" ;
        val++ ;
        
        val += toh(N-1, aux, to, from) ;
        
        return val ;
    }

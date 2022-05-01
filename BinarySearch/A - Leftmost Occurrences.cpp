#include <iostream>
# include<vector>
 
using namespace std;
 
 
long long Leftmost_Occurrences ( vector <long long> &vect , long long value , long long L , long long R )
 
{  
    
    if (R >= L)
    {
        long long mid =(L+R) / 2;
        
        if ((mid == 0 || value > vect[mid - 1]) && vect[mid] == value)
            return mid;
            
            
         else if (value > vect[mid])
            return Leftmost_Occurrences(vect, value, (mid + 1), R);
        else
            return Leftmost_Occurrences(vect,  value, L, (mid - 1));
    }     
         return -1;     
            
    
    
    
}
 
 
int main()
{
    long long n ; 
    cin>>n ; 
    
    vector <long long> a ; 
    vector <long long> b ; 
    
    for(int i = 0 ; i< n ; i ++)
   { long long l; 
    cin>>l; 
    a.push_back(l);}
    
     long long m ; 
    cin>>m ; 
    
    
        for(int i = 0 ; i< m ; i ++)
   {long long l; 
    cin>>l; 
   b.push_back(l);}
    
    long long  result;
    
for(int j = 0 ; j< m ; j ++)
   {   
       
       result = Leftmost_Occurrences ( a , b[j] , 0 , n-1 ) ; 
       
       if (result != -1)
       {cout << result +1 ;}
       
       else {cout<< result;}
       
      cout<<" ";
       
       
   }
    
    
 
    return 0;
}
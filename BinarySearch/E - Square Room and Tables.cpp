#include <iostream>
#include <cmath>
//#include <math.h>
using namespace std;
 
 
bool can (long long  M , long long n , long long a , long long b )
{
    if (((M/a)*(M/b)) >= n)
    
    return true;
    
    else return false;
}
 
int main()
{
    int t ;
    cin>> t; 
    long long L ;
    long long R;
    long long M ;
    
    for ( int i = 0 ; i < t ; i++)
    {  long long n , a, b ; 
       cin>>n>> a >> b; 
       
      if (n == 1) 
      cout << max(a , b) <<endl;
      
      else {
       L = 0 ;
       R =  n * max (a,b);
      
       while (R - L > 1  )
       {
         
          M= (R+L) / 2;    
          
          if (can (M , n , a, b )) 
           R= M ;
           
          else 
          L = M;
       }
        
    cout << R << endl;
    
      }
    
    }
    
    
 
    return 0;
}
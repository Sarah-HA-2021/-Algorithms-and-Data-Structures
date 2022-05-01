#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool can (vector <int> a , int k  , int n , int value )
{  
    if (a[n-1] < k )
    return false ;
    
    else {
    int sum = 0; 
    for (int i = n -1 ; i>=0 ; i --)
     sum = sum + (a[i] / k);
     
     if (sum >= value)
     return true;
     
     else return false;
    }
    
   
    
}
 
 
int main()
{
    int n , k ;
 
    vector <int> a;
    
    cin>>n>>k;
    
    for (int i = 0 ; i < n ; i ++)
     {int l ; 
     cin>>l ;
     a.push_back(l);}
     
     sort (a.begin(),a.end());
     
    int L = 0 ; 
    int R = a[n-1] + 1 ; 
    
    int M ;
    
    while (R - L > 1)
    {  M = (L+ R) /2 ; 
       if (can (a,M ,n , k))
       L = M;
       
       else R= M;
      
    } 
    
    cout<< L ; 
    
    return 0;
}
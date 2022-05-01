#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
 
int main()
{
    int n , m ; 
    vector<int> a , b ; 
    cin>> n ; 
    
    for (int i = 0 ; i < n ; i++)
    {  int l ; 
       cin>>l ;
       a.push_back(l);
        
    }
    
    sort(a.begin(), a.end());
    
    cin>> m; 
        for (int i = 0 ; i < m ; i++)
    {  int l ; 
       cin>>l ;
       b.push_back(l);
    }
    
    int res=0;
    int k=0; 
    
     for (int j = 0 ; j < m ; j++)
     {
      k = b[j]  ;
      res= lower_bound(a.begin(), a.end(), k) -a.begin();
      
      if (res==n && n>= 2 )
        cout << min (abs(a[n-1]- k)  ,  abs(a[n-2]- k) );
        
      else if (res==n && n==1)
      cout << abs(a[n-1]- k) ;
      else if ( res != n && n==1)
      cout <<  abs(a[res]- k);
      
      else if ( res != n && n>= 2)
      cout << min (abs(a[res]- k)  ,  abs(a[res-1]- k) );
      
      cout<<endl;
     // else if ( )
    //cout<< res << " "; 
     }
    
    
    return 0;
}
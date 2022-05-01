#include <iostream>
#include<vector>
 
using namespace std;
 
int main()
{
   int n ;
  vector <int> h; 
  vector <int> result1 ; 
  vector <int> result2 ;
  cin>>n;
  
  for (int i=0; i< n ; i++)
  {
     int k;
     cin>>k ;
     h.push_back(k); 
  }
  
int u;
int j ;
 
 for (int i= n-1; i>= 0 ; i--)
  {  u = i ;
    
      while ( ( (2*u) + 1 ) < n )
      
      {   j =   (2*u) + 1 ;
          
          if  ( ((j+1) < n) &&  (h[j+1] > h[j]) )
          j++;
          
        if (h[u] < h[j])  
          {
              //cout << u << " " << j << endl;
              result1.push_back (u);
              result2 .push_back (j);
              
               std::swap(h[j],h[u]);
               u = j;
          }
          
          else break;
      }
      
    
  }
 
cout <<  result1.size() << endl; 
 
for (int i = 0 ; i < result1.size() ; i++ )
    cout << result1[i] << " "  <<  result2[i] << endl;
 
for (int i = 0 ; i < h.size() ; i++ )
cout<<h[i]<<" ";
 
    return 0;
}
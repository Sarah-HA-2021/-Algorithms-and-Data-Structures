#include <iostream>
#include <vector>
using namespace std;
 
int heapify ( vector <int> &h , int u , int n )
{ 
 
 
 
int j ;
int count = 0 ; 
      while ( ( (3*u) + 1 ) < n )
      
      {   vector <int> Ind;
          j =   (3*u) + 1 ;
          
          Ind.push_back(h[j]);
          
          if ((j+1) < n)
          Ind.push_back(h[j+1]);
          
             if ((j+2) < n)
          Ind.push_back(h[j+2]);
          
          int k = 0;
          int Max = Ind[k];
 
          for (int i = 0; i <Ind.size(); i++)
          {
          if (Ind[i] > Max)
          {
              Max = Ind[i];
              k = i;
               }
              }
          
          if (k==1)
            j=j+1;
            
          else if (k==2)
          j=j+2;
          //if  ( ((j+1) < n) &&  (h[j+1] > h[j]) )
         // j++;
          
         
          
        if (h[u] < h[j])  
          {
              //cout << u << " " << j << endl;
             // result1.push_back (u);
             // result2 .push_back (j);
              count ++;
               std::swap(h[j],h[u]);
               u = j;
          }
          
          else break;
      }
      
    
 
 
   return count; 
    
}
 
int main()
{
  int n ;
  vector <int> h; 
  cin>>n;
  
  for (int i=0; i< n ; i++)
  {
     int k;
     cin>>k ;
     h.push_back(k); 
  }
  
  int sum = 0 ;
  
 
 
// build it 
for (int i = n-1 ; i >=0 ; i--)
{   
    sum=sum+heapify( h , i, n) ;
}
 
 
 
  for (int i = n - 1; i > 0; i--) {
      
        swap(h[0], h[i]);
 
        sum=sum+heapify(h, 0, i);
    }
 
 
cout << sum << endl;
 
for (int i=0; i< n ; i++)
   cout<< h[i] << " " ; 
 
    return 0;
}
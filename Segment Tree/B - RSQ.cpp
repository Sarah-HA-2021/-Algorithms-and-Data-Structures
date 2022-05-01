#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
 
long long sum_q (vector <long long> &st,int v,int L,int R,int l,int r)
{
    if ((l<=L) and (R<=r))
    return st[v];
    
 
    if (R<l || L>r)
    return 0;
    
 
    int mid = (L + R) / 2;
    return sum_q(st,2*v+1, L, mid, l, r) + sum_q(st,2*v+2, mid+1, R, l, r);
 
    
    
}
 
 
long long modefiy_q (vector <long long> &st,int v,int L,int R,int i,int value)
{
    if (L==R)
    return st[v]=value;
    
 
    //if (R<l || L>r)
   // return 0;
    
    else{
    int mid = (L + R) / 2;
    
    
    if (i <= mid)
    modefiy_q (st,2*v+1, L,mid, i, value);
    else 
    modefiy_q (st,2*v+2, mid+1,R, i, value);
    //return sum_q(st,2*v+1, L, mid, l, r) + sum_q(st,2*v+2, mid+1, R, l, r);
   
   st[v]=st[2*v+1]+st[2*v+2];
   
    }
    
}
 
int main()
{ 
    int n ,m ;  // size of array and number of quries 
    cin>> n >>m;
    vector <int> a;
    
    for (int i=0 ; i<n; i++)
    {  int l;
       cin>>l;
       a.push_back(l);
    }
    
    // check that n is power to 2 
    int p1= ceil(log2 (n));
    int p2= floor(log2 (n));
    int k=0;
    
    if (p1 != p2)
   // round n to the nearest 2^k
    {
    
    while(ceil(log2 (n+k)) != floor(log2 (n+k)))
    {
        
        k++;
    }
    
    }
    
    //cout<<k;
    for (int j =0 ; j< k ; j++)
     {
         a.push_back(0);}
     
     
        //for (int j =0 ; j< n+k ; j++)
    // {cout<<a[j];}
     
vector<long long> b( 2*(n+k)-1, 0);
 
 
// intial 
 for (int j =0 ; j<n+k ; j++)
     {
         b[j+n+k-1]=a[j];
         
     }
 
 
 for (int j =2*(n+k)-2 ; j>=2; j=j-2)
     {   //cout<<(j-2)/2;
         //cout<<j;
        
        b[(j-2)/2]=b[j]+b[j-1];
         
    }
 
 //cout<<endl;
 //for (int j =0 ; j<b.size() ; j++)
  //  {  // cout<<endl;
       // cout<<b[j];
         
   // }
    
vector <int> res;
for (int j =0 ; j < m ; j ++)
{
    int u ,l,r; 
   cin>>u>>l>>r;
   if (u==1){  
       
       
       modefiy_q (b,0,0,n+k-1,l-1,r);
   // cout<<u<<" "<<l<<" "<<r<<endl;;
         /* l = l-1;
           int o;
           o=b[l+n+k-1];
           int inc=0;
           if (r>0)
           inc = o-r;
           else if(r<0)
           inc =r-o;
           
           
           b[l+n+k-1]=r;
           int y;
           if ((l+n+k-1)%2!=0)
           {   y = l+n+k-1;
           
               while(! (y==0))
               {  // i 
                   
                 b[(y-1)/2]=b[(y-1)/2] +inc;
                 y=(y-1)/2  ;
               }
               
               
           }
           
           else{
               
                y = l+n+k-1;
           
               while(! (y==0))
               {  // i 
                   
                 b[(y-2)/2]=b[(y-2)/2] +inc;
                 j=(y-2)/2  ;
               }
               
               
               
           }
      b[0]=b[0]+inc;*/
    }
    
       else if (u==0){
          //cout<<"yes"<<" "<<l<<" "<<r<<endl;
         cout<<sum_q (b,0,0,n+k-1,l-1,r-1);
          cout<<endl;
          // res.push_back(sum_q (b,0,0,n+k-1,l-1,r-1));
    }
 
}
 /*for (int j =0 ; j<b.size() ; j++)
   {  cout<<" ";
        cout<<b[j];
         
   }*/
   
 /*for (int j =0 ; j<res.size() ; j++)
   {  
        cout<<res[j];
        cout<<endl;
   }*/
//cout<<sum_q (b,0,0,n+k-1,0,4);
//cout <<endl;
//cout << sum_q (b,0,0,n+k-1,0,3);
    return 0;
}
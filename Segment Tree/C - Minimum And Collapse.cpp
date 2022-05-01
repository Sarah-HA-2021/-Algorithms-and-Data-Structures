#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
 
int min_q (vector <int> &st,int v,int L,int R,int l,int r)
{
    if ((l<=L) and (R<=r))
    return st[v];
    
 
    if (R<l || L>r)
    return 1000000001;
    
 
    int mid = (L + R) / 2;
    return min(min_q(st,2*v+1, L, mid, l, r) ,min_q(st,2*v+2, mid+1, R, l, r));
 
    
    
}
 
 
 
 
 
long long modefiy_q (vector <int> &st,vector <int> &st_ind,int v,int L,int R,int i,int value)
{
    if (L==R)
    {   st_ind[v]=i;
        return st[v]=value;}
    
 
    //if (R<l || L>r)
   // return 0;
    
    else{
    int mid = (L + R) / 2;
    
    
    if (i <= mid)
    modefiy_q (st,st_ind,2*v+1, L,mid, i, value);
    else 
    modefiy_q (st,st_ind,2*v+2, mid+1,R, i, value);
    //return sum_q(st,2*v+1, L, mid, l, r) + sum_q(st,2*v+2, mid+1, R, l, r);
   
   st[v]=min(st[2*v+1],st[2*v+2]);
   
   if (st[2*v+1]<st[2*v+2])
       st_ind[v]=st_ind[2*v+1];
    else 
        st_ind[v]=st_ind[2*v+2];
    }
    
}
 
 
 
 
long long sum_q (vector <long long> &st,int v,int L,int R,int l,int r)
{
    if ((l<=L) and (R<=r))
    return st[v];
    
 
    if (R<l || L>r)
    return 0;
    
 
    int mid = (L + R) / 2;
    return sum_q(st,2*v+1, L, mid, l, r) + sum_q(st,2*v+2, mid+1, R, l, r);
 
    
    
}
 
 
long long modefiy_sum_q (vector <long long> &st,int v,int L,int R,int i,int value)
{
    if (L==R)
    return st[v]=value;
    
 
    //if (R<l || L>r)
   // return 0;
    
    else{
    int mid = (L + R) / 2;
    
    
    if (i <= mid)
    modefiy_sum_q (st,2*v+1, L,mid, i, value);
    else 
    modefiy_sum_q (st,2*v+2, mid+1,R, i, value);
    //return sum_q(st,2*v+1, L, mid, l, r) + sum_q(st,2*v+2, mid+1, R, l, r);
   
   st[v]=st[2*v+1]+st[2*v+2];
   
    }
    
}
 
 
 
 
 
int main()
{ 
    int n  ;  // size of array and number of quries 
    cin>> n ;
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
         a.push_back(1000000001);}
     
     vector<int> indeces;
     
     for (int j =0 ; j< n+k ; j++)
     {
         indeces.push_back(1);}    
     
     
     
        //for (int j =0 ; j< n+k ; j++)
    // {cout<<a[j];}
     
vector<int> b( 2*(n+k)-1, 0);
vector<int> d( 2*(n+k)-1, 0);
vector<long long> c( 2*(n+k)-1, 0);
 
 
 
// intial 
 for (int j =0 ; j<n+k ; j++)
     { // cout<<"j "<<j<<endl;
         b[j+n+k-1]=a[j];
         d[j+n+k-1]=j;
         c[j+n+k-1]=1;
         
     }
 
 for (int j =2*(n+k)-2 ; j>=2; j=j-2)
     {   //cout<<(j-2)/2;
         //cout<<j;
        
        b[(j-2)/2]=min(b[j],b[j-1]);
        if (b[j]<b[j-1])
         d[(j-2)/2] =d[j];
        else
         d[(j-2)/2] =d[j-1];
         c[(j-2)/2]=c[j]+c[j-1];
         
    }
 
 
 //cout<<b[0]<<endl;
 //cout<<d[0]+1<<endl;
 
 
    
 //cout<<d[0]+1<<endl;
 
 for (int t =0 ; t<n;t++)   
  {
      
//std::vector<int>::iterator it = std::find(a.begin(), a.end(), b[0]);
//int index = std::distance(a.begin(), it);
 
//cout<<index <<" "<<b[0]<<endl;
int ind=d[0];
if (ind ==0)
cout <<ind+1;
 
else
{ cout<<sum_q (c,0,0,n+k-1,0,ind-1)+1;}
cout<<" ";
   //   try
   //  {cout <<sum_q (c,0,0,(2*n)-1,0,index-1)<<" ";}
   //   catch (const std::exception& e) // reference to the base of a polymorphic object
//{
  // std::cout << 0<<" "; // information from length_error printed
//}
//cout<<index;
 
 
modefiy_q (b,d,0,0,n+k-1,ind,1000000001);
modefiy_sum_q (c,0,0,n+k-1,ind,0);
 
      
  
} 
 /*
 modefiy_q (b,0,0,n+k-1,i,1000000001);
 modefiy_sum_q (c,0,0,n+k-1,i,0);
 
 for (int j =0 ; j<b.size() ; j++)
   {   cout<<" ";
        cout<<b[j];
         
   }
   
   cout<<endl;
   for (int j =0 ; j<c.size() ; j++)
   {   cout<<" ";
        cout<<c[j];
         
   }
 //cout<<d[0]+1;
 modefiy_q (b,0,0,n+k-1,0,1000000001);
 modefiy_sum_q (c,0,0,n+k-1,0,0);
    cout<<endl;
   for (int j =0 ; j<c.size() ; j++)
   {   cout<<" ";
        cout<<c[j];
         
   }
 //cout<<endl;
 //for (int j =0 ; j<b.size() ; j++)
  //  {  // cout<<endl;
       // cout<<b[j];
         
   // }
   
 
 //for (int j =0 ; j<d.size() ; j++)
 // {  cout<<" ";
    //  cout<<d[j];
         
  //}
   //for (int j =0 ; j<b.size() ; j++)
 //{   //cout<<b[0];
     //cout <<b[0];
     //cout<<endl;
   //modefiy_q (b,0,0,n+k-1,d[0],1000000001);
 // }
 
/*for (int j =0 ; j<b.size() ; j++)
   {  
        cout<<b[j]<<" " ;} 
cout<<"b0: "<<b[0]<<endl;
modefiy_q (b,0,0,n+k-1,d[0],1000000001);
for (int j =0 ; j<b.size() ; j++)
   {  
        cout<<b[j]<<" " ;} 
cout<<"b0: "<<b[0]<<endl;
modefiy_q (b,0,0,n+k-1,0,1000000001);
for (int j =0 ; j<b.size() ; j++)
   {  
        cout<<b[j]<<" " ;} 
cout<<"b0: "<<b[0]<<endl;
modefiy_q (b,0,0,n+k-1,3,1000000001);
for (int j =0 ; j<b.size() ; j++)
   {  
        cout<<b[j]<<" " ;} 
cout<<"b0: "<<b[0]<<endl;
modefiy_q (b,0,0,n+k-1,4,1000000001);
for (int j =0 ; j<b.size() ; j++)
   {  
        cout<<b[j]<<" ";} 
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
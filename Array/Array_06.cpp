 /*
 Find the count number of subarrays with sum==k

 1-Based Indexing

 Brute Force:-For Every Index j.We will count the number of valid Subarrays which have sum k and ending at j
 */
/*
Find Sum of Range [1.....r] where (l<=r) using Prefix Sum
*/







#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int CountofSubarraysBruteForce(vector<int> &arr ,int k)
{
   int n=arr.size();
   
   int count=0;
   for(int j=1;j<n;j++)
   {
       int curr_sum=0;
      for(int i=j;i>=1;i--)
      {
         curr_sum+=arr[i];
         if(curr_sum==k)
         {
            count++;
         }
      }
   }
   return count;
 }
int CountofSubarraysOptimizedApproach(vector<int>& arr, int k)
{
  /*
  we are maintaining prefix_sum[n+1,0] we keep analysing p[j]-p[i]==k then that range is equal to k 
  */
 int n=arr.size();//this n+1we pass
 vector<int> prefix(n,0);
 int cnt=0;
 
 for(int i=1;i<n;i++)
 { 
    prefix[i]=prefix[i-1]+arr[i];
 }
 for(int j=1;j<n;j++)
 {
    for(int i=0;i<j;i++)
    {
        if(prefix[i]==prefix[j]-k)
          cnt++;
    }
 }
 return cnt;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
         cin>>arr[i];
    }
    cout<<CountofSubarraysBruteForce(arr,k);

  
    
}




  
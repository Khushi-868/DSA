/*
Find the largest/smallest subarray whose sum==k
*/
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
   
 }
vector<int> CountofSubarraysOptimizedApproach(vector<int>& arr, int k)
{
  int n=arr.size();
  int largest=0;
   

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




  
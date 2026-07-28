/*
Find Sum of Range [1.....r] where (l<=r) using Prefix Sum
*/







#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int ValidAbsoluteDifferenceBruteForce(vector<int> &arr ,int k)
{
   
}
int ValidDifferenceAbsoluteOptimizedApproach(vector<int>& arr, int l,int r)
{
    int n=arr.size();
   vector<int> prefix_sum(n);
   prefix_sum[0]=arr[0];
   for(int i=1;i<n;i++)
   {
     prefix_sum[i]=prefix_sum[i-1]+arr[i];
   }
   if(l==0)
        return prefix_sum[r];
   return( prefix_sum[r]-prefix_sum[l-1]);

}

int main()
{
  vector<int> arr = {3,2,3,3,1};
   cout<<ValidDifferenceAbsoluteOptimizedApproach(arr,1,4);
}



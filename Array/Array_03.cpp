/*
Count all i,j pairs where i<j and abs(b[i]-b[j])=k[k>0]
Brute force:- use nested loops for i check j=i+1 to n where abs(b[i]-b[j]==k) cnt;
Print of All Valid pairs .
Optimized Approach:-
 */




#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int ValidAbsoluteDifferenceBruteForce(vector<int> &arr ,int k)
{
   int n=arr.size();
   int cnt=0;
   for(int i=0;i<n;i++)
   {
     for(int j=i+1;j<n;j++)
     {
         if(abs(arr[i]-arr[j])==k)
         {
            cnt++;
         }
     }
   }
   return cnt;
}
int ValidDifferenceAbsoluteOptimizedApproach(vector<int>& arr, int k)
{
    unordered_map<int, int> mp;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(arr[i] - k) != mp.end())
            cnt += mp[arr[i] - k];

        if (mp.find(arr[i] + k) != mp.end())
            cnt += mp[arr[i] + k];

        mp[arr[i]]++;
    }

    return cnt;
}

int main()
{


  vector<int> arr = {3,2,3,3,1};
   cout<<ValidDifferenceAbsoluteOptimizedApproach(arr,2);


    
}

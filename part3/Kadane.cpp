/*
Kadane's Algorithm
*/







#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


int maxSubarraySum(vector<int> &b)
{
  int prev=b[0],T=0;
  int n=b.size();
  for(int i=1;i<n;i++)
  {
     int curr=max(b[i]+prev,b[i]);
     curr=max(curr,0);
     prev=curr;
     T=max(T,curr);
  }
  return T;

}

int main()
{
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int result=maxSubarraySum(b);
    cout<<"Maximum subarray is"<<result<<endl;
    return 0;
}
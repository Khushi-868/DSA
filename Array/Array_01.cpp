// Check if there are any two Equal numbers in a array at a distance less than or equal to k.
// if arr={3,1,2,3,2} and k=1
// so we need to find the two equal numbers in the array which are at a distance less than or equal to k.
//Let's take an example an array={3,2,3,3,1}
/**
 Brute approach= take i,j suchthat j-i<=k(to check an array has equal elements)
 i=0 j=1,2,3
 i=1 j=2,3,4
 i=2 j=3,4
 i=3 j=4

    

 **/




#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


bool containsNearbyDuplicateBruteForce(vector<int> &arr ,int k)
{
    int n=arr.size();
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<n && j<=i+k;j++)
        {
            if(arr[i]==arr[j])
                return true;
        }
    }
    return false;
}
bool containsNearbyDuplicateHashMap(vector<int> arr ,int k)
{
    int n=arr.size();
    unordered_map<int,int> mp;
    mp[arr[0]]=0;
    for(int i=1;i<n;i++){
      if(mp.find(arr[i]) !=mp.end())
      {
          if(i-mp[arr[i]]<=k)
             return true;
          
      }
       mp[arr[i]]=i;
    }
    return false;
}
int main(){
  vector<int> arr = {3,2,3,3,1};

bool found = containsNearbyDuplicateHashMap(arr, 1);
  if(found)
  {
    cout<<"Exist";
  }
  else 
    cout<<"Not Exist";


    
}

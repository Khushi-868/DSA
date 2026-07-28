/*
Valid Anagram
*/







#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


bool isAnagramBruteForce(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

bool isAnagramOptimized(string s, string t)
{
    if (s.size() != t.size())
    return false;
   unordered_map<char,int> count;
   for(int i=0;i<s.size();i++)
   {
       count[s[i]]++;
   }
   for(char ch :t)
   {
      count[ch]--;
      if(count[ch]<0)
      {
         return false;
      }
   }
   return true;
}

int main()
{
  string s,t;
  cout<<"Enter string"<<endl;
  cin>>s>>t;
  if(isAnagramOptimized(s,t))
      cout<<"Anagram";
  else
      cout<<"Not Anagram";
}




  
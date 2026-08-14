// First Unique Character in a string
// using hashing
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
       int firstUniqChar(const string &s)
       {
           unordered_map<char,int> freq;
           for(char c: s) freq[c]++;
           for(size_t i=0;i<s.size();++i)
               if(freq[s[i]]==1) return static_cast<int>(i);
           return -1;
       }
    /** ek loop se krna we can use idx to store first unique character */
    int firstUniqCharAnother(const string &s)
       {
           unordered_map<char,int> freq;
           int idx=0;
           for(char c: s)
           { 
            freq[c]++;
            if(freq[s[idx]]>1)
            {
                idx=idx+1;

               while(freq[s[idx]]>1)
               {
                 idx++;
               }
               if(idx ==s.size()) return -1;

            }
           


           }
           return idx;
        }
};
int main()
{
   

    Solution obj;

    string s = "leetcode";

    int ans = obj.firstUniqCharAnother(s);

    cout << "First unique character index: " << ans << endl;

    return 0;

}
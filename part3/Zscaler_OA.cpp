#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

/*
 * Complete the 'pilesOfBoxes' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY boxesInPiles as parameter.
 */

long long pilesOfBoxes(vector<int> boxesInPiles) {

    // WRITE YOUR CODE HERE
    int n=boxesInPiles.size();
    long long steps =0;
    
    while(true)
    {
       bool allequal=true;
       for(int i=1;i<n;i++)
       {
          if(boxesInPiles[i]!=boxesInPiles[i-1])
          {
              allequal=false;
              break;
          }
       }
        if(allequal)
            break;
        int largestindex=0;
        int largest=boxesInPiles[0];
        int secondlargest=INT_MIN;
        for(int i=1;i<n;i++)
        {
            if(largest< boxesInPiles[i])
            {
               secondlargest=largest;
               largest=boxesInPiles[i];
               largestindex=i;
            }
            else if(boxesInPiles[i]<largest && boxesInPiles[i]>secondlargest )
            {
                secondlargest=boxesInPiles[i];
            }
        }
        boxesInPiles[largestindex]=secondlargest;
        steps++;

    }
    return steps;


}
long long pilesOfBoxesOptimized(vector<int> boxesInPiles)
{
    map<int,int> mp;
    long long steps=0;
    int n = boxesInPiles.size();
    for(int i = 0; i < n; i++)
    {
        mp[boxesInPiles[i]]++;
    }
    int eleabove=0;
    


    for(auto it=mp.rbegin();it!=mp.rend();it++)
    {
          int count= it->second;
          steps+=eleabove;
          eleabove+=count;


    }
    return steps;
}
// second i make g vector pair to store all elements of map
long long pilesOfBoxesOptimized_part2(vector<int> boxesInPiles){
     map<int,int> mp;
    long long steps=0;
    int n = boxesInPiles.size();
    for(int i = 0; i < n; i++)
    {
        mp[boxesInPiles[i]]++;
    }
    vector<pair<int,int>> g;
    for(auto u: mp)
    {
        g.push_back({u.first,u.second});

    }
   
    int step=0;
    for(int i=g.size()-1;i>=1;i--)
    {
        g[i-1].second+=g[i].second;
        step+=g[i].second;
        g[i].second=0;
    }
    return step;
}





int main() {
    // DO NOT WRITE CODE HERE
    vector<int> boxesInPiles = {5, 5,5,2,2,1};

    long long ans = pilesOfBoxesOptimized_part2(boxesInPiles);

    cout << ans << endl;

    return 0;
}
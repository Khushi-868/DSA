#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
long long dp[2001][5001];
const ll MOD = 1000000007;

int digitSum(int x) {
    int sum = 0;

    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}
int main()
{

   int n;
   cin>>n;
   vector<int> required_sums(n);

for(int i = 0; i < n; i++) {
    cin >> required_sums[i];
}
  dp[0][0]=1;
  for(ll i=1;i<=n;i++)
  {
    
    for(ll j=1;j<=5000;j++)
    {
        if(digitSum(j)==required_sums[i-1]){
 
				for(ll j1=0;j1<=j;j1++){
					dp[i][j] = (dp[i][j] + dp[i-1][j1]) % MOD;
				}
 
			}else{
				dp[i][j] = 0;
			}
    }
  }
  ll ans=0;
  for(ll j=0;j<=5000;j++)
  {
    ans+=dp[n][j];
  }
  cout<<ans;

    return 0;
}
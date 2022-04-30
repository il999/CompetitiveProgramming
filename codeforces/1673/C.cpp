//coding template
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[500][40001];
void solve()
{
    int n;
    cin>>n;
    //cout<<sizeof(dp)/1048576.0 <<"\n";
    cout<<dp[498][n]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
   int  n=40001;
    vector<long long> palin;
    string p;
    bool b=true;
    int m=0;

    for(int i=1;i<=n;i++)
    {
        p=to_string(i);
        b=false;
        m=p.size();
        for(int i=0;i<=(m+1)/2-1;i++)
        {
            if(p[i]!=p[m-i-1])
            {
                b=true;
            }
        }
        if(!b)
        {
            palin.push_back(i);
        }
    }
    //cout<<palin.size()<<"\n";
    long long p1=40001;


    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {

        dp[0][i]=0;
    }
    for (int i = 1; i <= palin.size(); i++) {
    for (int j = 0; j <= n; j++) {

      dp[i][j] = dp[i-1][j];
      int left = j-palin[i-1];
      if (left >= 0) {
        (   dp[i][j] += dp[i][left]);
            dp[i][j]%=MOD;
      }


    }
  }
    while(t--)
        solve();
}

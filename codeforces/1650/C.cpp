#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    vector<int> v1;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(b,i+1));
        v1.push_back(a);
    }
    sort(v.begin(),v.end());
    long long w=0;
     vector<pair<int,int>> v2;
    for(int i=0;i<n*2;i++)
    {
        w+=v[i].first;
        v2.push_back(make_pair(v1[v[i].second-1],v[i].second));

    }
    cout<<w<<"\n";
    sort(v2.begin(),v2.end());
    for(int i=0;i<n;i++)
    {

        cout<<v2[i].second<<" "<<v2[n*2-i-1].second<<"\n";
    }


}
int main() {
  int t;
  cin>>t;
  while(t--)
    solve();
}

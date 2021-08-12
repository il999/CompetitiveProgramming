#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{

  int n;
  cin>>n;
  int l[n];
  double count1=0;
  double max1=0;

  for(int i=0;i<n;i++)
  {

    cin>>l[i];

  }
  sort(l,l+n);
  for(int i=0;i<n-1;i++)
  {
    count1+=l[i];
  }



  count1/=(n-1);
  count1+=l[n-1];
  cout << fixed << setprecision(10)<<count1<<endl;

}
int main()
{
  ios_base::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
      solve();
    }
}

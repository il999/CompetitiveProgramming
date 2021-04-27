#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> a;
    int thing;
    int ones=0;
    int zeros=0;
    for(int i=0;i<n;i++)
    {
      cin>>thing;
      a.push_back(thing);
      if(thing==1)
      {
        ones++;
      }else
      {
        zeros++;
      }
    }

    for(int i=0;i<q;i++)
    {
      int t;
      cin>>t;
      int xk;
      cin>>xk;
      xk--;
      if(t==1)
      {
        if(a[xk]==0)
        {
          a[xk]=1;
          zeros--;
          ones++;
        }else
        {
          a[xk]=0;
          zeros++;
          ones--;
        }
      }else
      {
        
        if(ones>xk)
        {
          cout<<1<<endl;
        }else
        {
          cout<<0<<endl;
        }
      }
    }
}

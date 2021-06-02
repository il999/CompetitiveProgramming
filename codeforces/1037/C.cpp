#include <iostream>

using namespace std;

int main()
{
    int n;
    string a;
    string b;

    cin>>n;
    cin>>a;
    cin>>b;
    int zeroflip=-1;
    int oneflip=-1;
    int cost=0;
    for(int i=0;i<n;i++)
    {
      if(a[i]!=b[i])
      {
        if(a[i]=='0')
        {
          if(oneflip!=-1&&i-oneflip<2)
          {
            cost=cost;
          }else
          {
            zeroflip=i;
            cost++;
          }

        }else
        {
          if(zeroflip!=-1&&i-zeroflip<2)
          {
            cost=cost;
          }else
          {
            oneflip=i;
            cost++;
          }
        }
      }
    }
    cout<<cost<<endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    int a[n];
    int b[q];
    int thing;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];

    }
    for(int i=0;i<q;i++)
    {
      cin>>b[i];
    }
    for(int i=0;i<q;i++)
    {
      // for(int j=0;j<n;j++)
      // {
      //   cout<<a[j]<<" ";
      // }
      // cout<<endl;

      for(int j=0;j<n;j++)
      {
        bool found=false;
        if(a[j]==b[i])
        {

          cout<<j+1<<" ";
          thing=a[0];
          a[0]=a[j];
          if(j!=0)
          {


          for(int p=1;p<n;p++)
          {

            if(!found)
            {
              int life=a[p];
              a[p]=thing;
              thing=life;


              if(a[p]==a[j])
              {
                found=true;
              }
            }else
            {
              break;
            }

          }
        }


          break;
        }
      }

    }
    cout<<endl;

}

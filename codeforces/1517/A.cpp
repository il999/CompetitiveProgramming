#include <iostream>
#include <math.h>
using namespace std;
int len(long long n)
{
  int p=0;
  while (n!=0)
  {
    p++;
    n/=10;
  }
  return p;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
      long long n;
      cin>>n;
      long long p=n/2050;
      int thing=18;
      int q=1;
      int ans=0;

      if(n<2050)
      {
        cout<<-1<<endl;
      }else if(n%2050!=0)
      {
        cout<<-1<<endl;
      }
      else
      {
        while(q!=0)
        {
          for(int i=thing;i>=0;i--)
          {
            if(n/(2050*pow(10,i))>=1)
            {
              thing=i;
              break;
            }
          }
          long long life=2050*pow(10,thing);
          n-=life;

          ans++;
          if(n<2050)
          {
            cout<<ans<<endl;
            q--;
          }


        }
    }
    }
}

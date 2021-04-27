#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,k;
      cin>>n>>k;
      int a[n];
      if(n<k*2+1)
      {
        cout<<-1<<endl;

      }else
      {
        for(int i=0;i<n;i++)
        {
          a[i]=-1;
        }
        int p=n-k;
        for(int i=1;i<n;i+=2)
        {
          if(k>0)
          {
            a[i]=p+k;
            k--;
          }
        }
        int count=1;
        for(int i=0;i<n;i++)
        {
          if(a[i]==-1)
          {
            a[i]=count;
            count++;
          }
        }
        for(int i=0;i<n;i++)
        {
          cout<<a[i]<<" ";
        }
        cout<<endl;
      }
    }
}

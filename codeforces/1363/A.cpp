#include <iostream>

using namespace std;

int main()
{
  int t;
  cin>>t;

  while(t--)
  {
    bool print=false;
    int odds=0;
    int evens=0;
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i]%2==0)
      {
        evens++;
      }else
      {
        odds++;
      }
    }
    if(evens==0&&x%2==0)
    {
      cout<<"NO"<<endl;
      print=true;
    }else
    {
    if(odds>0)
    {
      if(odds%2==0)
      {

        if(odds-1+evens>=x)
        {
          cout<<"YES"<<endl;
          print=true;
        }else
        {
          cout<<"NO"<<endl;
          print =true;
        }

      }else
      {
        if(odds+evens>=x)
        {


        cout<<"YES"<<endl;
        print=true;
      }
      }
    }else
    {
      cout<<"NO"<<endl;
      print=true;
    }
  }
    if(!print)
    {


    cout<<"NO"<<endl;
  }
  }
}

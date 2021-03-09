#include <iostream>

using namespace std;

int main()
{
    int n;
    int t;
    cin>>n>>t;
    int l[n-1];
    for(int i=0;i<n-1;i++)
    {
      cin>>l[i];
    }
    int index=1;
    while (index<=t)
    {

      if(index==t)
      {

        cout<<"YES"<<endl;
        return 0;
      }

      index=index+l[index-1];
    }
    cout<<"NO"<<endl;
}

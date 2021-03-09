#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n];
    for(int i=0;i<n;i++)
    {
      cin>>l[i];
    }
    int even=0;
    int odd=0;
    int oddn;
    int evenn;
    for(int i=0;i<n;i++)
    {
      if(l[i]%2==0)
      {
        evenn=i+1;
        even++;
      }else
      {
        oddn=i+1;
        odd++;
      }
    }
    if(odd<even)
    {
      cout<<oddn<<endl;
    }else
    {
      cout<<evenn<<endl;
    }

}

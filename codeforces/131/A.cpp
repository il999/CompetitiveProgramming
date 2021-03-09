#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    bool check=false;
    for(int i=1;i<s.size();i++)
    {
      if(s[i]>=97)
      {
        check=true;
      }
    }
    if(check==false)
    {


    if(s[0]>96)
    {
      s[0]-=32;
    }else
    {
      s[0]+=32;
    }

    for(int i=1;i<s.size();i++)
    {
      if(s[i]<97)
      {
        s[i]+=32;
      }
    }
  }
    cout<<s<<endl;
}

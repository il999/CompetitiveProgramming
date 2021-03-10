#include <iostream>

using namespace std;
int reverse(string s1, int n)
{
  string s2="";
  for(int i=n-1;i>=0;i--)
  {
     s2+=s1[i];
  }
  int reversed=0;;
  for(int i=0;i<n;i++)
  {
    if(s1[i]==s2[i])
    {
      reversed++;
    }else
    {
      return reversed;
    }
  }
return reversed;

}


int main()
{
  int t;
  cin>>t;
  int n;
  int k;
  string s;
  while (t--)
  {

    cin>>n;
    cin>>k;

    cin>>s;
    if(n%2==0 &&n/2==k)
    {
      cout<<"NO"<<endl;
    }
    else if(reverse(s,n)>=k)
    {
      cout<<"YES"<<endl;
    }else
    {
      cout<<"NO"<<endl;
    }
  }
  return 0;

}

#include <iostream>

using namespace std;

int main()
{
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    string s3="";
    for(int i=0;i<s1.size();i++)
    {
      if(s1[i]=='1'&&s2[i]=='0')
      {
        s3+='1';
      }else if((s1[i]=='0'&&s2[i]=='1'))
      {
        s3+='1';
      }


      else
      {
        s3+='0';
      }
    }
    cout<<s3<<endl;
}

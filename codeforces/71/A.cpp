#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        if(s[i].size()<=10)
        {
            cout<<s[i]<<endl;

        }else{
            cout<<s[i][0]<<s[i].size()-2<<s[i][s[i].size()-1]<<endl;
        }
    }


}

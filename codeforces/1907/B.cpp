#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int B=0;
        int b=0;
        string ne="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='B') B++;
            else if(s[i]=='b') b++;
            else if(isupper(s[i])){
                if(B>0){
                    B--;
                }else ne+=s[i];
            }else{
                if(b>0){
                    b--;
                }else ne+=s[i];
            }
        }
        reverse(ne.begin(),ne.end());
        cout<<ne<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int long long;


void solve(){
    int n,m;
    cin>>n>>m;
    cout<<"? 1 1"<<endl;
    cout.flush();
    int t1,t2;
    cin>>t1;
    cout<<"? 1 "<<m<<endl;
    cout.flush();
    cin>>t2;

    int x = (t1+t2-(m-1))/2;
    int y = (t1-x)+1;

    x++;
    if(x<=0||y<=0||x>n||y>m){
        x=2;
        y=2;
    }
    cout<<"? "<<x<<" "<<y<<endl;
    cout.flush();
    int t3;
    cin>>t3;
    if(t3==0){
        cout<<"! "<<x<<" "<<y<<endl;
        cout.flush();
    }else{
        cout<<"? "<<n<<" "<<m<<endl;
        cout.flush();
        cin>>t3;
        y = m-(t2+t3-(n-1))/2;
        x = t2 - (t2+t3-(n-1))/2+1;
      //  cerr<<t2<<" "<<t3<<"\n";
        cout<<"! "<<x<<" "<<y<<endl;
        cout.flush();
    }



}
int main() {
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}

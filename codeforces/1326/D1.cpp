//coding template
/*
⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉
*/
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
string LongestPalindromicPrefix(string str)
{

    // Create temporary string
    string temp = str + '?';

    // Reverse the string str
    reverse(str.begin(), str.end());

    // Append string str to temp
    temp += str;

    // Find the length of string temp
    int n = temp.length();

    // lps[] array for string temp
    int lps[n];

    // Initialise every value with zero
    fill(lps, lps + n, 0);

    // Iterate the string temp
    for (int i = 1; i < n; i++) {

        // Length of longest prefix
        // till less than i
        int len = lps[i - 1];

        // Calculate length for i+1
        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }

        // If character at current index
        // len are same then increment
        // length by 1
        if (temp[i] == temp[len]) {
            len++;
        }

        // Update the length at current
        // index to len
        lps[i] = len;
    }

    // Print the palindromic string of
    // max_len
    return temp.substr(0, lps[n - 1]);
}
void solve()
{
    int n;
    string s;
    cin>>s;
    n=s.size();

    string temp="";


    string pre_backwards[n];
    int in=0;

    while(s[in]==s[n-in-1]&&in<n-in-1)
    {
        in++;
    }
    string s2="";

    for(int i=in;i<n-in;i++)
    {
        s2+=s[i];
    }

   // cout<<s2<<"\n";
    string  prefix= LongestPalindromicPrefix(s2);
    string backwardss2="";
    for(int i=s2.size()-1;i>=0;i--)
    {
        backwardss2+=s2[i];
    }
    string  suffix= LongestPalindromicPrefix(backwardss2);
    string middle=prefix;
    if(suffix.size()>prefix.size())
    {
        middle=suffix;
    }
    for(int i=0;i<in;i++)
    {
        cout<<s[i];
    }
    cout<<middle;
    for(int i=in-1;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<"\n";




}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

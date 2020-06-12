#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "geeksforgeeks";
    int n=s.size();
    int arr[26] = {0};
    int index;
    char ch;
    for(int i=0;i<n;i++)
    {
        index = s[i]-97;
        arr[index] = arr[index]+1;
    }
    int count = 0;
    for(int i=0;i<26;i++)
    {
        count = arr[i];
        while(count--)
        {
            ch = i+97;
            cout<<ch;
        }
    }
    cout<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int duplicateParen(string str)
{
    int n;
    char ch;
    stack<char> s;
	n=str.size();
    int revCount = 0;
    int countOpen = 0;
	for(int i=0;i<n;i++)
	{
	    ch = str[i];
        cout<<"current symbol:"<<ch<<endl;
	    if(ch == '}')
	    {
	        if(s.empty())
	        {
                revCount++;
                ch = '{';
                s.push(ch);
                countOpen++;
	        }   
	        else if(s.top() == '{')
	        {
	            s.pop();
	            countOpen--;
	        }
	    }
        else
	    {
	       s.push(ch);
           countOpen++;
	    }
    }
        return (revCount + (countOpen/2));
}

int main()
 {
	//code
	int t;
	string str;
	cin>>t;
	while(t--)
	{
	    cin>>str;  
        cout<<duplicateParen(str)<<endl;
    }
	return 0;

}
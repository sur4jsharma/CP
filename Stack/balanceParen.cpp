#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n;
	char ch;
	char temp;
	string str;
	stack<char> s;
	cin>>t;
	while(t--)
	{
	    cin>>str;
	    while(!s.empty())
	    {
	        s.pop();
	    }
	    n=str.size();
	    for(int i=0;i<n;i++)
	    {
	        ch = str[i];
	        if(ch == '(' || ch == '{' || ch == '[')
	        {
	            s.push(ch);
	        }
	        else if(!s.empty())
	        {
	            temp = s.top();
                if((ch=='}' && temp=='{') || (ch==')' && temp=='(') || (ch==']' && temp=='[') )
	                s.pop();
                else
	            {
	                break;
	            }
	        }
	        else
	        {
	            s.push(ch);
	            break;
	        }
	    }
	    if(s.size() == 0)
	        cout<<"balanced"<<endl;
	   else
	        cout<<"not balanced"<<endl;
	}
	return 0;
}
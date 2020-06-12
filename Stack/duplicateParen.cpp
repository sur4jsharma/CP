#include<bits/stdc++.h>
using namespace std;

bool duplicateParen(string str)
{
    int n;
    char ch;
    stack<char> s;
	n=str.size();
    int count = 0;
    int flag = 0;
	for(int i=0;i<n;i++)
	{
	    ch = str[i];
        //cout<<"current symbol is:"<<ch<<endl;
	    if(ch == ')')
	    {
            //cout<<"pop from stack start"<<endl;
	        while(!s.empty() && s.top() != '(')
            {
                //cout<<s.top()<<endl;
                count++;
                s.pop();
            }
            s.pop();
            if(!count)
            {
                flag = 1;
                break;
            }
            count = 0;
	    }
        else
	        s.push(ch);
    }
        return flag;
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
	}
    if(duplicateParen(str))
        cout<<"duplicate parenthesis exist"<<endl;
    else
        cout<<"no duplicate parenthesis exist"<<endl;
	return 0;

}
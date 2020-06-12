#include<bits/stdc++.h>
using namespace std;

void stockSpan(int arr[],int n)
{
    stack<int> s;
    int count = 1;
    int curr;
    int span[n];
    span[0] = 1;
    for(int i=1;i<n;i++)
        span[i] = 0;
    int prev_top = n-1;
    for(int i=n-1;i>-1;i--)
    {
        curr = arr[i];
        cout<<"current element is: "<<curr<<endl;
        while(!s.empty() && curr>arr[s.top()])
        {
            // cout<<"span of "<<arr[s.top()]<<" is found and is: "<<span[s.top()]<<endl;
            span[s.top()]+= 1;
            prev_top = s.top();
            // cout<<"span of "<<s.top()<<" is:"<<count<<endl;
            s.pop();
            if(!s.empty())
                span[s.top()]+= span[prev_top];
        }
        // count++;
        s.push(i);
    }
    while(!s.empty())
    {
        span[s.top()] = s.top()+1;
        s.pop();
    }
    for(int i=0;i<n;i++)
        cout<<span[i]<<" ";
}

int main()
 {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        cout<<endl;
        stockSpan(arr,n);
        cout<<endl;
	}
	return 0;
}
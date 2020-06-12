#include<bits/stdc++.h>
using namespace std;

void nextGreater(long int arr[],int n)
{
    stack<int> s;
    long int curr;
    int value;
    int index;
    for(int i=0;i<n;i++)
    {
        curr = arr[i];
        cout<<"curr is:"<<curr<<endl;
        while(!s.empty() && curr > arr[s.top()])
        {

            arr[s.top()] = curr;
            cout<<"next greatest:"<<arr[s.top()]<<endl;    
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        index = s.top();
        arr[index] = -1;
        s.pop();
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main()
 {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
	    nextGreater(arr,n);
	    cout<<endl;
	}
	return 0;
}
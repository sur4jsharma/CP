#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum=16;
	int x1,x2,l,r;
	int arr[]={1, 4, 45, 6, 10, -8};
	int size = sizeof(arr)/sizeof(int);
	sort(arr,arr+size);
	l=0;
	r=size-1;
	while(l<r)
	{
		if(arr[l]+arr[r] == sum)
		{
			x1=arr[l];
			x2=arr[r];
			sum=0;
			break;
		}
		else if(arr[l]+arr[r] > sum)
		{
			r--;
		}
		else
		{
			l++;
		}
	}
	if(sum==0)
		cout<<"Two numbers are: "<<x1<<" "<<x2<<endl;
	else
		cout<<"No such pair"<<endl;
}

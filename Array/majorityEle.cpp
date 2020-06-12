#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={3, 3, 4, 2, 4, 4, 2, 4};
	int size = sizeof(arr)/sizeof(int);
	int majEle=arr[0],count=1;
	for(int i=1;i<size;i++)
	{
		if(majEle == arr[i])
			count++;
		else
			count--;
		if(count == 0)
		{
			majEle = arr[i];
			count=1;
		}
	}
	count=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i] == majEle)
			count++;
	}
	if(count>(size/2))
		cout<<majEle<<endl;
	else
		cout<<"No Majority Element"<<endl;
	
}

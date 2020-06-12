#include<bits/stdc++.h>
using namespace std;

int max_diff_usingMaxMin(int arr[],int n)
{
	int min=INT_MAX,max=INT_MIN;
	int temp=0;
	int maxDiff = -1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=min)
		{
			min=arr[i];
		}
		if(arr[i]>=max)
		{
			max=arr[i];
			temp = max-min;
			if(i!=0 && (temp > maxDiff))
				maxDiff = temp;
		}
	}
	return maxDiff;
}

int max_sum_subarray(int arr[],int n)
{
	int max_sum = 0;
	int max_sofar = 0;
	for(int i=0;i<n;i++)
	{
		max_sofar += arr[i];
		if(max_sofar > max_sum)
			max_sum = max_sofar;
		else if(max_sofar < 0)
			max_sofar = 0;
	}
	return max_sum;
}

int max_diff_using_kadane(int arr[],int n)
{
	int diff_arr[n-1];
	for(int i=0;i<n-1;i++)
	{
		diff_arr[i] = (arr[i+1] - arr[i]);
	}
	return max_sum_subarray(diff_arr,n-1);
}

int main()
{
	int max_diff;
	int arr[]={321, 54, 8, 470, 217, 223, 343, 8, 464, 261, 448, 294, 131, 218, 44};
	int n = sizeof(arr)/sizeof(int);
	// max_diff = max_diff_usingMaxMin(arr,n);
	max_diff = max_diff_using_kadane(arr,n);

	cout<<"Max difference is : "<<max_diff<<endl;
}
		

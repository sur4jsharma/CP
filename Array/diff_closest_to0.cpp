#include<iostream>
using namespace std;

long int closestPairN(int arr[],int n)
{
	long int minSum = INT_MAX;
	long int x,y;
	for(int i=0;i<n-1;i++)
	{
	    for(int j=i+1;j<n;j++)
	    {
	        if(abs(arr[i] + arr[j]) < minSum)
	        {
	            x = arr[i];
	            y = arr[j];
	            minSum = abs(x+y);
	        }
	    }
	}
	return (x+y);
}

int closestPair(int arr[],int n,int num)
{
	//cout<<"current number is:"<<num<<endl;
	int i,j,mid,minDiff=INT_MAX;
	i=0;
	j=n-1;
	while(i<j)
	{
		mid= arr[(i+j)/2] != num? (i+j)/2 : (i+j)/2 +1;
		//cout<<"mid element is:"<<arr[mid]<<endl;
		if(arr[mid] != num)
		{
			minDiff=arr[mid]+num;
			minDiff = abs(minDiff);
		//	cout<<"Min sum is:"<<minDiff<<endl;
			if(((mid + 1)<=j) && (abs((arr[mid+1] + num)) < minDiff))
			{
				mid = mid +1;
				i=mid+1;
			}
			else if(((mid-1)>=0) && (abs((arr[mid-1] + num)) < minDiff))
			{
				mid = mid -1;
				j=mid-1;
			}
			else
				break;
		}
		
	}
	return arr[mid];
}

int closestPairUsingSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	int minSum = INT_MAX;
	int l=0;
	int r=n-1;
	int x,y;
	int sum;
	while(l<r)
	{
		cout<<"elements are: "<<arr[l]<<" "<<arr[r]<<endl;
	    sum = arr[l] + arr[r];
		cout<<"Sum is:"<<sum<<endl;
		if( abs(sum) < minSum )
	    {
	        minSum = abs(sum);
			x=arr[l];
			y = arr[r];
			cout<<"MIN Sum:"<<minSum<<endl;
	    }	
	    if( sum < 0)
	    {
	        l++;
	    }
	    else if( sum > 0)
	    {
	        r--;
	    }
	    else
	    {
	        l=r;        
	    }
	    
	}
	cout<<x<<" "<<y<<endl;
	return (x+y);
}

int main()
{
	int arr[] {1, 60, -10, 70, -80, 85};
   	int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    printf("%d\n",closestPairUsingSort(arr,n));

	/*
	// int n;
	// cin>>n;
	// int arr[n];
	// for(int i=0;i<n;i++)
	// {
	// 	cin>>arr[i];
	// }
	int arr[] = {-21, -67, -37, -18, 4, -65};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n);
	int x1,x2,minDiff=INT_MAX,temp;
	for(int i=0;i<n-1;i++)
	{
		x1 = arr[i];
		temp = closestPair(arr,n,arr[i]);
		x2 = temp;
		//cout<<"Two numbers are:"<<x1<<" "<<x2<<endl;

		if(abs(temp + arr[i]) < minDiff)
		{
			x1=arr[i];
			x2 = temp;
			minDiff=abs(temp + arr[i]);	
		}
	}
	cout<<"Two numbers are:"<<x1<<" "<<x2<<endl;
	*/
}

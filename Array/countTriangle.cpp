#include<bits/stdc++.h>
using namespace std;

int countTrianble(int arr[],int n)
{
    int noOfTriangles =0;
    int s1,s2,s3;
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int j,k;
    int count = 0;
    for(int i=0;i<n-2;i++)
    {
        s1 = arr[i];
        k = i+1;
        j = i+2;
        while(j<n)
        {
            if(j==n-1 && (s1+arr[k] > arr[j]))
            {
                noOfTriangles++;
                count = (j-(k+1))*(j-k)/2;
                noOfTriangles += count;
                break;
            }
            if(s1+arr[k] > arr[j])
            {
                noOfTriangles++;
                j++;
            }
            else
            {
                k++;
                count = j - (k+1);
                noOfTriangles += count;
            }
        }
        //cout<<"No of triangles when starting from:"<<s1<<" is:"<<noOfTriangles<<endl;
    }

    return noOfTriangles;
}

int main()
{
    int arr[] = {10, 21, 22, 100, 101, 200, 300};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of Triangles: "<<countTrianble(arr,n)<<endl;
    return 0;
}
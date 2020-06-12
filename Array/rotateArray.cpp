#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
    if(y == 0)
        return x; 
    return gcd(y,x%y);
}

void rotateArray(int arr[],int n,int d)
{
    int set_size = gcd(n,d);
    int temp;
    int j,k;
    //cout<<hcf<<endl;
    for(int i=0;i<set_size;i++)
    {
        temp = arr[i];  
        cout<<temp<<endl;      
        j=i;
        while(1)
        {
            k=j+d;
            if(k>=n)
            {
                k=k-n;
                arr[j]=temp;
            }
            arr[j]=arr[k];
            if(k==i)
            {   
                arr[j]=temp;
                break;
            }
            j=k;
        }  
    }
    for(int index=0;index<n;index++)
    {
        cout<<arr[index]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7,8,9,10,11};
    int d = 4;
    int n=sizeof(arr)/sizeof(arr[0]);
    rotateArray(arr,n,d);
}
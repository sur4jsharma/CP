#include<bits/stdc++.h>
using namespace std;

void count_sort(int arr[],int n)
{
    int c_arr[9]={0};
    for(int i=0;i<n;i++)
        c_arr[arr[i]]++;

    int j=0;
    for(int i=0;i<9;i++)
    {
        while(c_arr[i])
        {
            arr[j++]=i;
            c_arr[i]--;
        }
    }
}

void multipleOfThree(int *arr,int n)
{
    sort(arr,arr+n);
    int index = -1;
    int sum=0;
    int count=0;
    int flag = 1;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    if(sum%3==2)
    {
    //remove 1 smallest element that gives remainder as 2 and then print the array
        for(int i=0;i<n;i++)
        {
            if(arr[i]%3==2)
            {
                arr[i]=-1;
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            for(int i=0;i<n;i++)
            {
                if((arr[i]%3 == 1 &&  count !=2))
                {
                    arr[i]=-1;
                    count++;
                }
            }
            if(count == 2)
                flag = 0;
        }
    }
    else if(sum%3==1)
    { 
    // remove 1 smallest element that gives remainder as 1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%3 == 1)
            {
                arr[i]=-1;
                flag = 0;
                break;
            }
        }
    }

    if(flag == 0 && (count!=n))
    {
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]!=-1)
                cout<<(arr[i]);
        }   
    }
    else
    {
        cout<<"Not Possible";
    }
    
}

int main()
{
    int arr[]={4 , 4 , 1 , 1 , 1 , 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    count_sort(arr,n);
    multipleOfThree(arr,n);
    cout<<endl;
}
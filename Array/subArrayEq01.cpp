#include<bits/stdc++.h>
using namespace std;

void maxSumArrayWith01(int arr[],int n)
{
    int sum = 0;
    int si=0;
    int li=-1;
    int max = INT_MIN;
    int temp_max = 0;
    map<int,int> m;
    map<int,int>::iterator it;
    int length = 0;
    for(int i=0;i<n;i++)
    {
        arr[i] == 1 ? sum++:sum--;
        if(sum==0)
        {
            max = i+1;
            li = i;
            si = 0;
        }
        else
        {
            it = m.find(sum);
            if(it != m.end())
            {
                temp_max = i - it->second;
                if(temp_max > max)
                {
                    max = temp_max;
                    si = it->second + 1;
                    li = i;
                }
            }
            m.insert({sum,i});
        }
    }
    length = li - si +1;
    cout<<length<<endl;
    // if(li != -1)
    //     cout<<"Starting index:"<<si<<" Ending index:"<<li<<endl;
    // else
    //     cout<<"No such sub array"<<endl;
}

int main()
{
    // int arr[] = {1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0};
    // //int arr[] = {0,0,1,1,0};
    // int n=sizeof(arr)/sizeof(arr[0]);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    maxSumArrayWith01(arr,n);
}
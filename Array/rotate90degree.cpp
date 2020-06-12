#include<bits/stdc++.h>
#define n 5
using namespace std;

void rotate_array(int arr[][n])
{
    int row = n;
    int col = n;
    int r,c;
    int limit_outer = row/2;
    int limit_inner = row;
    r=row-1;
    c=col-1;
    int sour,dest;
    int i,j;
    for(int k=0;k<limit_outer;k++)
    {
        j=0;
        for(int l=0;l<limit_inner-1;l++)
        {
            sour = arr[k+j][k];
            dest = arr[k+r][k+j];
            arr[k+r][k+j] = sour;

            sour = dest;
            dest = arr[k+r-j][c];
            arr[k+r-j][c] = sour;
   
            sour = dest;
            dest = arr[k][c-j];
            arr[k][c-j] = sour;
            
            arr[k+l][k] = dest;

            j++;
        }
        r-=2;
        c--;
        limit_inner-=2;
    }

}

int main()
{

    int arr[][n] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    //int row = sizeof(arr)/sizeof(arr[0]);
    //int col = sizeof(arr[0])/sizeof(arr[0][0]);
    cout<<"Before Rotation"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    rotate_array(arr);
    //cout<<"row:"<<row<<" col:"<<col<<endl;
    cout<<"After final rotation"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}
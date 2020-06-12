#include<bits/stdc++.h>
using namespace std;

void productArray(int arr[],int n)
{
    int leftpro[n];
    int rightpro[n];
    leftpro[0] = 1;
    rightpro[n-1] = 1;
    int lmul = arr[0];
    int rmul = arr[n-1];
    int j;
    //storing product of all left elements and right elements of current element
    for(int i = 1;i<n;i++)
    {
        leftpro[i] = lmul;
        lmul = lmul * arr[i];
        j=n-i-1;
        rightpro[j]=rmul;
        rmul = rmul * arr[j];
    }
    /*
    for(int i=0;i<n;i++)
        cout<<leftpro[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<rightpro[i]<<" ";
    cout<<endl;
    */

   for(int i=0;i<n;i++)
   {
       cout<<(leftpro[i] * rightpro[i])<<" ";
   } 
   cout<<endl;
}

void proArrayUsngLog(int arr[],int n)
{
    double sum = 0;
    double res_sum,mul;
    for(int i=0;i<n;i++)
    {
        sum += log10(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        res_sum = sum - log10(arr[i]);
        mul = pow(10,res_sum);
        cout<<mul<<" ";
    }
    cout<<endl;

}
int main()
{
    int arr[] = {10,3,5,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    productArray(arr,n);
    //proArrayUsngLog(arr,n);
}
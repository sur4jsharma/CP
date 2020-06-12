#include<bits/stdc++.h>
using namespace std;

int max_path_sum(int A[], int B[], int l1, int l2)
{

    //Your code here
    int sumA=0;
    int sumB=0;
    int temp_sum = 0;
    int i=0;
    int j=0;
    // int path;
    int sum=0;
    while(i<l1 && j<l2)
    {
        // sumA=A[i];
        // sumB=B[j];
        if(A[i] > B[j]) // A will wait for B until B[j] >= A[i]
        {
            while(B[j]<A[i])
                sumB+=B[j++];
        }
        else if(B[j] > A[i]) // B will wait for A until A[i] >= B[j]
        {
            while(A[i] < B[j])
                sumA+=A[i++];
        }
/*
17 34
1 1 1 1 2 2 4 4 5 5 5 6 7 7 8 8 9
1 1 1 1 1 1 2 2 2 2 2 2 3 3 3 3 3 4 4 4 4 5 5 6 6 7 7 7 7 8 8 8 9 9
*/
        if(A[i] == B[j])
        {
            cout<<"common element is:"<<A[i]<<endl;

            sum+= (sumA>sumB?sumA:sumB)+A[i];
            cout<<"sum is:"<<sum<<endl;
            cout<<"sumA:"<<sumA<<endl;
            cout<<"sumB:"<<sumB<<endl;
            sumA=0;
            sumB=0;
            //sum-=A[i];
            i++;
            j++;
            while(i<l1 && j<l2 && B[j] == A[i])
            {
                sum+= A[i++];
                j++;
                cout<<"in while sum is:"<<sum<<endl;
            }
        }
        
    }   
    cout<<"after while ends\n";
    cout<<"sum is:"<<sum<<endl;
    cout<<"sumA:"<<sumA<<endl;
    cout<<"sumB:"<<sumB<<endl;
     while(i<l1)
     {
         sumA+=A[i];
         i++;
     }
     while(j<l2)
     {
         sumB+=B[j];
         j++;
     }
     if(sumA>=sumB)
        sum+=sumA;
    else
        sum+=sumB;
    return sum;
    // cout<<sum<<endl;
    
}
/*
17 34
1 1 1 1 2 2 4 4 5 5 5 6 7 7 8 8 9
1 1 1 1 1 1 2 2 2 2 2 2 3 3 3 3 3 4 4 4 4 5 5 6 6 7 7 7 7 8 8 8 9 9
*/

int main()
{
    int t,n1,n2;
    // cin>>t;
    t=1;
    while(t--)
    {
        cin>>n1>>n2;
        int A[n1];
        int B[n2];
        for(int i=0;i<n1;i++)
            cin>>A[i];
        for(int i=0;i<n2;i++)
        {
            cin>>B[i];
        }
        cout<<max_path_sum(A,B,n1,n2)<<endl;
    }
    return 0;
}
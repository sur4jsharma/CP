#include<bits/stdc++.h>
using namespace std;

void findNumber(int ssum,int exor)
{
    int tempsum;
    int diff;
    int n1,n2;
    int temp = exor;
    int n = 0;

    //finding 2's complement;
    while(temp)
    {
        temp >>=1;
        n++;
    }
    int xor2s = pow(2,n) - exor;
    // 2's complement of xor of 2 number is difference b/w them
    diff = xor2s;
    cout<<diff<<endl;
    n1  = (ssum + diff)/2;
    n2 = ssum - n1;
    cout<<n1<<" "<<n2<<endl;
}

int main()
{
    int ssum= 11;
    int exor = 10;
    findNumber(ssum,exor);
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=10;
    int *ptr;
    ptr=&x;
    int **pptr;
    pptr = &ptr;
    cout<<x<<endl;
    cout<<&x<<endl;
    cout<<ptr<<endl;//stores address of x
    cout<<*pptr<<endl;//pptr stores address of ptr so *pptr will go to address of ptr and then print what ptr contains i.e address of x.
    cout<<&ptr<<endl;
    cout<<pptr<<endl;
    ptr = NULL;
    cout<<ptr<<endl;
}
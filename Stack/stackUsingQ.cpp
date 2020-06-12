#include<bits/stdc++.h>
using namespace std;

class QStack
{
    queue<int> q1;//contains all the elements
    queue<int> q2;// used to contains the q1 elements temporary
    public:
        void push(int x);
        int pop();
};

void QStack::push(int x) // making push costly
{
    int temp;
    while(!q1.empty())
    {
        temp = q1.front();
        q1.pop();
        q2.push(temp);
    }
    q1.push(x);
    while(!q2.empty())
    {
        temp = q2.front();
        q2.pop();
        q1.push(temp);
    }
}
 int QStack::pop()
 {
    int x = -1;
    if(!q1.emplace)
    {
        x=q1.front();
        q1.pop();
    }
     return x;
 }
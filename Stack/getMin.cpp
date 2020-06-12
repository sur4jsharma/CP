#include<bits/stdc++.h>
using namespace std;

class Stack
{
    stack<int> s;
    int min_ele = INT_MAX;

    public:
        void push(int x);
        int pop();
        bool isFull(int n);
        bool isEmpty();
        int getMin();
};

void Stack::push(int a)
{
     //add code here.
    if(s.empty())
    {
        s.push(a);
        min_ele = a;
    }
    else if(a >= min_ele)
    {
        s.push(a);
    }
    else
    {
        
        s.push(2*a - min_ele);
        min_ele = a;
    }
}

bool Stack::isFull(int n)
{
     //add code here.
     return (s.size() == n);
}

bool Stack::isEmpty()
{
    //add code here.
    return s.empty();
}

int Stack::pop()
{
    //add code here.
    int value = s.top();
    s.pop();
    if(value >=min_ele)
        return value;
    int temp = min_ele;
    min_ele = 2*temp - value;
    return temp;
}

int Stack::getMin()
{
   //add code here.
   return min_ele;
}

int main()
{
//     int n;
//     cin>>n;
//     int x;
//     Stack *st = new Stack();
//     while(!st->isFull(n))
//     {
//         cin>>x;
//         st->push(x);
//     }
//     cout<<st->getMin()<<endl;
    Stack st; 
    st.push(3);
    st.push(5);
    cout<<st.getMin()<<endl;
    st.push(2);
    st.push(1);
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.getMin()<<endl;
    st.pop();
 }
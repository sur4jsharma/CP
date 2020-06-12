#include<bits/stdc++.h>
using namespace std;
struct triangle
{
    int a,b,c;
};

void sortEdge(triangle &t)
{
    if(t.a > t.b)
        swap(t.a,t.b);
    if(t.b > t.c)
        swap(t.b,t.c);
    if(t.a > t.b)
        swap(t.a,t.b);
}

int uniqueTriangle(triangle t[],int n)
{
    int count = 0;
    int e1,e2,e3;
    set< pair< int,pair<int,int> > > s;
    for(int i=0;i<n;i++)
    {
        sortEdge(t[i]);
        e1=t[i].a;
        e2=t[i].b;
        e3=t[i].c;

        s.insert({e1,{e2,e3}});
    }
    count = s.size();
    return count;
}

int main()
{
    triangle t[]={{3, 2, 2}, {3, 4, 5}, {1, 2, 2}, {2, 2, 3}, {5, 4, 3}, {6, 4, 5}};
    int n = sizeof(t)/sizeof(t[0]);
    cout<<"Number of unique triangle is:"<<uniqueTriangle(t,n)<<endl;
    return 0;
}
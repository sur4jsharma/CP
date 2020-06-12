#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
   //Your code here
    queue<petrolPump> q;
    int petrol = 0;
    int distance = 0;
    // q.push(p[0]);
    int position = 0;
    for(int i=0;i<n;i++)
    {
        distance+= p[i].distance;
        petrol+= p[i].petrol;
        if(distance > petrol)
        {
            distance = 0;
            petrol = 0;
            q.push(p[i]);
            position = i+1;
        }
    }
    cout<<"distance:"<<distance<<endl;
    cout<<"petrol:"<<petrol<<endl;
    cout<<"position:"<<position<<endl;
    cout<<"size of queue is:"<<q.size()<<endl;
    // while(!q.empty())
    // {
    //     distance+= q.front().distance;
    //     petrol+= q.front().petrol;
    //     q.pop();
    //     if(distance > petrol)
    //         return -1;
    // }
    for(int i=0;i<n;i++)
    {
        distance+= p[i].distance;
        petrol+= p[i].petrol;
        if(distance > petrol)
        {
            return -1;   
        }
    }
    if(position < n)
        return position;
}

int main()
{
    int n;
    cin>>n;
    petrolPump p[n];
    for(int i=0;i<n;i++)
        cin>>p[i].petrol>>p[i].distance;
    cout<<tour(p,n);
    endl;
    return 0;
}
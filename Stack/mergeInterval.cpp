/*
set of pairs sorted on second element because default sorted on first element

#define pair<int,int> pairs

struct modified_comp
{
    bool operator()(const pairs& lhs, const pairs& rhs) const
    { 
        return lhs.second < rhs.second; 
    }
};

set<pairs,modified_comp> s;

*/

#include<bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
};

bool modified_comp(Interval i1,Interval i2)
{
    return (i1.start < i2.start);
}

void mergeInterval(Interval intervals[],int n)
{
    sort(intervals,intervals+n,modified_comp);
    for(int i=0;i<n;i++)
    {
        cout<<"("<<intervals[i].start<<","<<intervals[i].end<<")"<<" ";
    }
    cout<<endl;
    vector<pair<int,int> > v;
    vector<pair<int,int> >::iterator it;
    int vStart,vFinal;
    int tempStart,tempFinal;
    v.push_back(make_pair(intervals[0].start,intervals[0].end));
    for(int i=1;i<n;i++)
    {
        vStart = v.back().first;
        vFinal = v.back().second;
        tempStart = intervals[i].start;
        tempFinal = intervals[i].end;
        if(tempStart <= vFinal)
        {
            v.pop_back();
            tempStart = vStart;
            if(tempFinal < vFinal) 
                tempFinal = vFinal;
        }
        v.push_back(make_pair(tempStart,tempFinal));

    }
    it = v.begin();
    for(;it!=v.end();it++)
        cout<<it->first<<" "<<it->second<<" ";
}

int main()
{
    int n;
    cin>>n;
    Interval *intervals = (Interval *)malloc(n*sizeof(Interval));
    for(int i=0;i<n;i++)
    {
        cin>>intervals[i].start;
        cin>>intervals[i].end;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"("<<intervals[i].start<<","<<intervals[i].end<<")"<<" ";
    }
    cout<<endl;
    mergeInterval(intervals,n);
    cout<<endl;
}
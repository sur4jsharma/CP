#include<bits/stdc++.h>
using namespace std;

//0 means boys party
/*
void groupOccurance(int arr[],int n)
{
    unordered_map<int,pair<int,int> >m;
    unordered_map<int,pair<int,int> >::iterator it;
    pair<int,int> pr;
    it = m.begin();
    int count = 0;
    int i=0;
    int element;
    int firstPos,countTillNow;
    int filled=0;
    // pr = it->second;
    // element = pr.second;
    // cout<<element<<endl;

    for(int i=0;i<n;i++)
    {
        it = m.find(arr[i]);
        // cout<<"number to find;"<<arr[i]<<endl;
        if(it == m.end())
        {
            m.insert({arr[i], {i,1}});
            it = m.find(arr[i]);
            // element = it->first;
            // firstPos = (it->second).first;
            // countTillNow = (it->second).second;
            // cout<<"element:"<<element<<"\t"<<"first position:"<<firstPos<<"\t"<<"total occurance:"<<countTillNow<<endl;
        }
        else
        {
            countTillNow = (it->second).second;
            countTillNow+= 1;
            firstPos = (it->second).first;
            m.erase(it);
            m.insert({arr[i], {firstPos,countTillNow}});
        }
    }
    //cout<<m.size()<<endl;
    for(it = m.begin(); it!=m.end();it++)
    {
        element = it->first;
        firstPos = (it->second).first;
        countTillNow = (it->second).second;
        cout<<"element:"<<element<<"\t"<<"first position:"<<firstPos<<"\t"<<"total occurance:"<<countTillNow<<endl;
        if(firstPos <= filled)
            while(countTillNow--)
                arr[filled++] = element;
        else
            while(countTillNow--)
                arr[firstPos++] = element;
    }
    for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
       cout<<endl;
}
*/

void groupOccurance(int arr[],int n)
{
    unordered_map<int,int> m;
    vector<int> v;
    vector<int>::iterator it;
    int count = 0;
    int element;
    int i = 0;
    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i]) == m.end())
        {
            v.push_back(arr[i]);
        }
        m[arr[i]]++;
    }
    for(it = v.begin();it!=v.end();it++)
    {
        element = (*it);
        count = m[element];
        while(count--)
            arr[i++] = element;
    }
}



int main()
 {
	//code
	int t=1,n,k;
	// cin>>t;
	while(t--)
	{
        int arr[] = {1, 2, 3, 1, 4, 5};
        n=sizeof(arr)/sizeof(arr[0]);
	    // cin>>n;
        // cin>>k;
	    // int arr[n];
	    // for(int i=0;i<n;i++)
	    //     cin>>arr[i];
	   groupOccurance(arr,n);
       for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
       cout<<endl;
	}
	return 0;
}
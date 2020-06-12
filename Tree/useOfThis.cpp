#include<bits/stdc++.h>
using namespace std;
class thisDemo
{
  int x;
  public:
    void setX(int x)
    {
        this->x = x;
    } 
    thisDemo get_copy()
    {
        return *this;//return copy of current object
    }
    thisDemo& get_reference()
    {
        return *this;
    }
    thisDemo* getPointer()
    {
        return this;
    }
    int get()
    {
        return this->x;
    }
};
int main()
{
    thisDemo ob;
    ob.setX(5);
    thisDemo *obptr;
    obptr = ob.getPointer();//set address of ob to obptr;
    cout<<&ob<<endl;
    cout<<obptr<<endl;
    thisDemo& obref = ob.get_reference(); // now obref and ob will have same address;
    cout<<&obref<<endl;
}
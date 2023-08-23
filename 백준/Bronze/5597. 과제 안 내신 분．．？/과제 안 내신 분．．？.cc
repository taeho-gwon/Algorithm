#include<iostream>
#include<set>
using namespace std;

set<int> s;
int main()
{
    for(int i=1;i<=30;i++)s.insert(i);
    for(int i=1;i<=28;i++)
    {
        int x;
        cin>>x;
        s.erase(x);
    }
    cout<<*s.begin()<<" "<<*(next(s.begin()));
}
/**
Input::

**/
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#define fw(x) freopen(x,"w",stdout)
#define For(i,a,b) for(int i = a;i < b;i++)
#define ll long long
#define ull unsinged long long
#define pb push_back
#define sc scanf
#define pf printf
#define fast ios_base::sync_with_stdio(0)
using namespace std;

struct data
{
    int a,b;
    int c;
    data(){};
    data(int u,int v,int w):a(u),b(v),c(w) {}

    bool operator <(const data& p) const
       {
           return a<p.a;
       }
    bool operator >(const data& p) const
        {
            return a>p.a;
        }
    struct data operator +(const data& p)const
    {
        return {a+p.a,b+p.b,c+p.c};

    }

};
int main()
{
    data aa(1,2,3);
    data bb(4,5,6);
//
//    if(aa>bb)
//        cout<<"try"<<endl;
//    else
//        cout<<"No"<<endl;
//    cout<<aa+bb<<endl;
    data c=aa+bb;

    cout<<c.a<<" "<<c.b<<" "<<c.c<<endl;
    return 0;
}


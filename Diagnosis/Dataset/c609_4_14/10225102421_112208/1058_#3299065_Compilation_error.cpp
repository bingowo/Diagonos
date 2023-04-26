#include<iostream>
using namespace std;

const int N=102;
const int R=-2;

typedef struct
{
    int sign,d[N],i1,i2;
}T;

int isZero(T n)
{
    return n.i1==n.i2 && n.d[n.i1]==0;
}

T Dec(T n,int b)
{
    if (b)
    {
        if (!n.sign)
            n.d[n.i2]--;
        else
        {
            int i;
            n.d[i=n.i2]++;
            while (n.d[i]>9)
                n.d[i]=0,n.d[--i]++;
            if (i<n.i1)
                n.i1--;
        }
    }
    return n;
}

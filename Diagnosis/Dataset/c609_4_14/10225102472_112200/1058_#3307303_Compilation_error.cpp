#include<bits/stdc++.h>
using namespace std;

const int N(102);
const int R(-2);

struct T
{
    int sign, d[N], i1, i2;
};

int isZero(T n)
{
    return n.i1 == n.i2 && n.d[n.i1] == 0;
}
T Dec(T n, int b)
{
    if(b)
    {
        if(!n.sign)
        {
            n.d[n.i2]--;
        }

        else
        {
            int i;
            n.d[i=n.i2]++;
            while(n.d[i]>9)
            {
                n.d[i]=0;
                n.d[--i]++;
            }
            
            if(i<n.i1)
            {
                n.i1--;
            }
        }
    }
    
    return n;
}
T DivR(T n)
{
       int i, t, carry=0; 
       n.sign = !n.sign;
       for(i=n.i1; i<=n.i2; i++)
       {        
           t=n.d[i]&1, n.d[i]=(carry*10+n.d[i])/-R, carry=t;
       }
}
#include <stdio.h>
#include <math.h>
int main()
{
    int a,n,m,x,res;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x==1) res = a;
    else if(x==2) res = a;
    else if(x==3) res = 2*a;
    else
    {
        int p = m-2*a,q[100] = {0,1},sum = 0,z,i,j;
        for(i = 1;i<n-4;i++)
            {if(i>1) q[i] = q[i-1]+q[i-2];
            sum = sum+q[i];}
        q[i] = q[i-1]+q[i-2];
        p = p-sum*a;
        z = p/(sum+q[i]);
        res = 2*a;
        for(j = 3;j<x;j++)
            {res = res + q[j-2]*z+q[j-3]*a;}

    }
    printf("%d",res);
    return 0;

}

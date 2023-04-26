#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int S,n;scanf("%d%d",&S,&n);
    n++;int d[n];double t[n],v[n],min;
    d[n-1]=S;int i,k;
    for(i=0;i<n-1;i++)
    {
        scanf("%d %d",&d[i],&v[i]);
        t[i]=(S-d[i])/v[i];
        if(i==0){min=t[0];k=0;}
        else
            if(min>t[i]){min=t[i];k=i;}
    }
    v[n-1]=S/((S-d[k])/v[k]);
    printf("%.6lf",v[n-1]);
}
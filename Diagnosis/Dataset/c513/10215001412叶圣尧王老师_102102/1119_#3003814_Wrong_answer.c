#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int S,n;scanf("%d%d",&S,&n);
    int d[n],v[n];double t[n],min;
    int i,k;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&d[i],&v[i]);
        t[i]=(S-d[i])/(double)v[i];
        if(i==0){min=t[0];k=0;}
        else
            if(min<t[i]){min=t[i];k=i;}
    }
    printf("%.6lf",(double)S/((S-d[k])/v[k]));
}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int yin(int m,int n)
{
    int c;
    if(m>n) {c=m;m=n;n=c;}
    if(m==1) return 1;
    else if(n%m==0) return m;
    else return yin(n%m,m);
}

typedef struct{int m;int z;}fenshu;

int main()
{
    int n;
    scanf("%d",&n);
    fenshu*w;
    w=(fenshu*)malloc(sizeof(fenshu)*n);
    int mc=1,zj=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d/%d",&w[i].z,&w[i].m);
        mc*=w[i].m;
    }
    int ansm=w[0].m,zm,zz;
    for(int i=1;i<n;i++)
        ansm=yin(ansm,w[i].m);
    mc/=ansm;
    for(int i=0;i<n;i++)
        {w[i].z*=mc/w[i].m;zj+=w[i].z;}
    //printf("%d %d %d\n",mc,ansm,zj);
    int g=yin(mc,zj);
    zm=mc/g;
    zz=zj/g;
    printf("%d/%d",zz,zm);

    return 0;
}
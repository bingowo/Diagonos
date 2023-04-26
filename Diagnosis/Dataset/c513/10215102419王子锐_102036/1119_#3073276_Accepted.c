#include<stdio.h>
typedef struct{int s,v;} car;
int main()
{
    int d,n,i;
    scanf("%d\n%d\n",&d,&n);
    car a[1001];
    for(i=0;i<n;++i)
    {
        scanf("%d%d",&a[i].s,&a[i].v);
        a[i].s=d-a[i].s;
    }
    int fz,fm;
    fz=a[0].s,fm=a[0].v;
    for(i=1;i<n;++i)
    {
        if((long long)fz*a[i].v<(long long)fm*a[i].s)
        {
            fz=a[i].s;
            fm=a[i].v;
        }
    }
    double dl=d,fml=fm,fzl=fz;
    double f=dl*fml/fzl;
    printf("%.6f",f);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
    int a,b;
}; 
int cmp(const void*m,const void*n)
{
    return (*(struct st*)m).a-(*(struct st*)n).a;
}
int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n,i;scanf("%d",&n);struct st d[n];
        for(i=0;i<n;i++)
            scanf("%d %d",&d[i].a,&d[i].b);
        qsort(d,n,sizeof(d[0]),cmp);
        for(i=0;i<n-1;i++)
        {
            if(d[i].a==d[i+1].a)
            {
                if(d[i].b!=d[i+1].b)
                    {printf("Poor dxw!\n");break;}
            }
        }
        if(i==n-1)
        {
            int flag=1;
            for(i=0;i<n&&flag==1;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(d[i].a==d[j].b){flag=-1;break;}
                }
            }
            if(flag==1)printf("Poor dxw!\n");
            else printf("Poor dxw!\n");
        }
        
        
    }
}
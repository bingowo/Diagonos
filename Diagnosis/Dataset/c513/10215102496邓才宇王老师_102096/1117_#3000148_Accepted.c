#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long int ansx;
    long long int ansy;
}ANS;
int cmp(const void *p1,const void *p2)
{
    ANS*a=p1;
    ANS*b=p2;
    if((*a).ansx > (*b).ansx) return 1;
    else if((*a).ansx<(*b).ansx) return -1;
    else
    {
        if((*a).ansy>(*b).ansy) return 1;
        else if((*a).ansy<(*b).ansy) return -1;
        else return 0;
    }
}
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    int n;
    scanf("%d",&n);
    long long int ans[n+1];
    int i=0;
    long long int xi[n+1],yi[n+1];
    ANS q[n+1];
    long long int min=0;
    int num=0;
    scanf("%lld %lld",&xi[0],&yi[0]);
    ans[0]=(labs(xi[0]-x)>labs(yi[0]-y))?labs(xi[0]-x):labs(yi[0]-y);
    min=ans[0];
    for(i=1;i<n;i++)
    {
        scanf("%lld %lld",&xi[i],&yi[i]);
        ans[i]=(labs(xi[i]-x)>labs(yi[i]-y))?labs(xi[i]-x):labs(yi[i]-y);
        if(min>ans[i])
        {
            min=ans[i];
        }
    }
    for(int j=0;j<n;j++)
    {
        if(ans[j]==min)
        {
            q[num].ansx=xi[j];
            q[num].ansy=yi[j];
            num++;
        }
    }
    qsort(q,num,sizeof(ANS),cmp);
    printf("%lld\n",min);
    printf("%lld %lld\n",q[0].ansx,q[0].ansy);
}

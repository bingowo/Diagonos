
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int st;
    int ed;
}point;
int cmp(const void*a,const void*b)
{
    point *k1,*k2;
    k1=(point*)a;k2=(point*)b;
    if(k1->st!=k2->st){if(k1->st>k2->st)return 1;else return -1;}
    else {if(k1->ed>k2->ed)return 1;else return -1;}
}
int main()
{
    int t,i=0;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        point p[100];
        int n,j=0,k=0,f=1;
        scanf("%d",&n);
        for(j=0;j<n;j++){scanf("%d %d",&p[j].st,&p[j].ed);}
        for(j=0;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(p[j].ed==p[k].st){f=-1;break;}
            }
            if(f==-1)break;
        }
        qsort(p,n,sizeof(p[0]),cmp);
         for(j=0;j<n;j++)
        {
            if(p[j].ed==p[j].ed)continue;
            for(k=j+1;k<n;k++)
            {
                if(p[j].st==p[k].st){if(p[j].ed==p[k].ed)continue;else f=-1;break;}
               if(f==-1)break;
            }
            if(f==-1)break;
        }
        if(f==-1)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
    return 0;
}

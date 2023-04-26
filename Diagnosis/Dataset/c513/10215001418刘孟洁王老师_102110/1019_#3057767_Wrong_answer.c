#include<stdio.h>
#include<stdlib.h>

typedef struct
{
   int num,sco,win,fall;
}competition;

int compare(const void*a,const void*b)
{
    competition c=*(competition*)a;
    competition d=*(competition*)b;
    if(c.sco!=d.sco) return d.sco-c.sco;
    else if(c.win!=d.win) return d.win-c.win;
    else if(c.fall!=d.fall) return c.fall-d.fall;
    else return c.num-d.num;
}

int main()
{
    int m,n,a,b,c;
    competition s[1007];
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==0&&n==0)break;
        int i=0,j=0;
        for(j=0;j<n;j++)
        {
            s[j].num=j+1;
        }
        for(j=0;j<1007;j++)
        {
            s[j].sco=0;s[j].win=0;s[j].fall=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c==1)
            {
               s[a-1].sco+=3;s[a-1].win+=1;
               s[b-1].sco-=1;s[b-1].fall+=1;
            }
            else if(c==-1)
            {
                s[b-1].sco+=3;s[b-1].win+=1;
                s[a-1].sco-=1;s[a-1].fall+=1;
            }
            else if(c==0)
            {
                s[a-1].sco+=1;
                s[b-1].sco+=1;
            }
        }
        qsort(s,n,sizeof(s[0]),compare);
        for(j=0;j<n;j++)
        {
            printf("%d%c",s[j].num,j==n-1?'\n':' ');
        }
        

    }
    return 0;
}
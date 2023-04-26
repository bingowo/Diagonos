#include<stdio.h>
#include<string.h>

typedef struct
{
   int num,sco,win,fall
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
void sort(competition *a,int n)
{
    qsort(a,n,sizeof(competition),compare);
}

int main()
{
    int m,n,a,b,c;
    while(m!=0&&n!=0);
    {
        scanf("%d%d",&m,&n);
        competition *s=(competition*)malloc(n*sizeof(competition));
        int i=0,j=0;
        for(j=0;j<n;j++)
        {
            s[i].num=i+1;s[i].sco=0;s[i].win=0;s[i].fall=0;
        }
        int c;
        competition a,b;
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
                s[b-1].b+=3;s[b-1].win+=1;
                s[a-1].sco-=1;s[a-1].fall+=1;
            }
            else if(c==0)
            {
                s[a-1].sco+=1;
                s[b-1].sco+=1;
            }
        }
        sort(s,n);
        for(j=0;j<n;j++)
        {
            printf("%d%c",s[j].num,j==n-1?'\n':'');
        }
        free(s);
    }
    return 0;
}

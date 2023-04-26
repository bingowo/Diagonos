#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quan=0;
typedef struct{
    char s[200];
    char temp[200];
    int t[200];
    int num;
}zi;
void f(zi* p)
{
    int len=strlen(p->s);
    int j=0,k=0;int n=0;
    for(int i=0;i<len-1;i++)
    {
        n++;
        if(p->s[i]!=p->s[i+1])
        {
            if(i==len-2)
            {
                p->temp[j++]=p->s[i];p->temp[j++]=p->s[i+1];
                p->t[k++]=n;p->t[k++]=1;n=0;
            }
            else {p->temp[j++]=p->s[i];p->t[k++]=n;n=0;}
        }
        if(i==len-2&&p->s[i]==p->s[i+1]) {p->temp[j++]=p->s[i];p->t[k++]=n+1;n=0;}
    }
    p->temp[j]='\0';
    p->num=j;
}
int cmp(const void *a,const void *b)
{
    zi *s1=(zi*)a,*s2=(zi*)b;
    if(s1->t[quan]>s2->t[quan]) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    zi* p=(zi*) malloc(t*sizeof(zi));
    for(int i=0;i<t;i++) scanf("%s",p[i].s);
    for(int i=0;i<t;i++) {f(p+i);}
    int bo=1;
    for(int i=0;i<t-1;i++)
    {
        if(strcmp(p[i].temp,p[i+1].temp)!=0) {bo=0;break;}
    }
    if(bo==0) printf("-1\n");
    else
    {
        int max=p[0].num;int sum=0;
        for(int i=0;i<max;i++)
        {
            quan=i;
            qsort(p,t,sizeof(zi),cmp);
            int allt=200;
            for(int j=t/2;j<(t/2+10);j++)
            {
                int tt=0;int nn=p[j].t[i];int k;
                for(k=0;k<t;k++)
                {
                    tt+=abs(p[k].t[i]-nn);
                }
                if(tt<allt) allt=tt;
            }
            sum+=allt;
        }
        printf("%d\n",sum);
    }
    return 0;
}

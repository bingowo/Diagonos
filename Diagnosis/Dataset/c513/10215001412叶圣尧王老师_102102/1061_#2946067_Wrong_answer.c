#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct st
{
    char c[16];
    char num[16];
    int len;
    int inlen;
};

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->len!=d->len)return c->len-d->len;
    else if(c->inlen!=d->inlen)return d->inlen-c->inlen;
    else if(strcmp(c->num,d->num)!=0)return strcmp(c->num,d->num);
    else  return strcmp(c->c,d->c);
}

int main()
{
    int T,i,j,k;char s[16];
    scanf("%d",&T);struct st d[T];
    for(int t=0;t<T;t++)
    {
        scanf("%s",s);k=0;
        d[t].c[0]=s[0];d[t].num[0]=1+'0';d[t].inlen=0;
        for(i=1;i<strlen(s);i++)
        {
            d[t].c[i]=s[i];
            for(j=0;j<i;j++)
            if(d[t].c[j]==s[i])
            {
                d[t].num[i]=d[t].num[j];
                d[t].inlen++;
                break; 
            }
            if(j==i)
            {
                if(k==1)k++;
                d[t].num[i]='0'+k++;
            }
        }
        d[t].c[i]='\0';d[t].num[i]='\0';d[t].len=i;
    }
    qsort(d,T,sizeof(d[0]),cmp);
    for(i=0;i<T;i++)
        printf("%s\n",d[i].c);
}
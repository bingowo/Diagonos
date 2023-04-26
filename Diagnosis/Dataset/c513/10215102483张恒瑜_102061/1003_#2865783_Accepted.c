#include<stdio.h>
#include<stdlib.h>

int count(long long a)
{
    int i,res=0;
    for(i=0;i<64;i++)
    {
        if(((unsigned long long)a<<(63-i)>>63)==1) res++;
    }
    return res;
}

int cmp(const void *a,const void *b)
{
    int i,acount=0,bcount=0;
    acount=count(*(long long *)a);
    bcount=count(*(long long *)b);
    if(acount==bcount) return *(long long *)a<*(long long *)b? -1:1;
    else return bcount-acount;
}
int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        long long input[10005]={0};
        int len,i;
        scanf("%d",&len);
        for(i=0;i<len;i++)
        {
            scanf("%lld",&input[i]);
        }
        qsort(input,len,sizeof(input[0]),cmp);
        
        printf("case #%d:\n",t);
        for(i=0;i<len;i++)
        {
            printf("%lld ",input[i]);
        }
        printf("\n");
        t++;
    }
    return 0;
}

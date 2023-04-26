#include<stdio.h>
#include<stdlib.h>
int dTob(long long a)
{
    int i=0,j=0;
    if(a>=0)
    {
        while(a!=0)
        {
            i=a%2;
            a/=2;
            if(i==1){j++;}
        }
        return j;
    }
    else
    {
        a+=9223372036854775808;
        while(a!=0)
        {
            i=a%2;
            a/=2;
            if(i==1){j++;}
        }
        return j;
    }

}

int cmp(const void *a,const void *b)
{
    long long _a=*(long long*)a;
    long long _b=*(long long*)b;
    int sa=dTob(_a),sb=dTob(_b);
    if(sa>sb) return 0;
    else if(sa<sb) return 1;
    else return *(int*)a-*(int*)b;
}

int main()
{
    int T,i,j,t;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        long long a[100000];
        scanf("%d",&t);
        for(j=0;j<t;j++){scanf("%lld",&a[j]);}
        qsort(a,t,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<t;j++) {printf("%lld ",a[j]);}
        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char s[30];
    int shu[30];
    int wei;
    unsigned long long yuan;
}bigint;

int cmp(const void*a,const void*b)
{
    bigint aa=*((bigint*)a);
    bigint bb=*((bigint*)b);
    int i;
    if(aa.wei>bb.wei) return -1;
    else if(aa.wei<bb.wei) return 1;
    else
    {
        for(i=0;i<aa.wei;i++)
        {
            if(aa.shu[i]>bb.shu[i]) return -1;
            else if (aa.shu[i]<bb.shu[i]) return 1;
        }
        return 0;
    }
}

bigint zhuan(bigint a)
{
    int len=strlen(a.s),i;
    for(i=0;i<len;i++)
    {
        a.shu[i]=a.s[i]-'0';
    }
    a.wei=len;
    a.yuan=0;
    for(i=0;i<len;i++)
    {
        a.yuan*=10;
        a.yuan+=a.shu[i];
    }

    /*printf("test:yuan=%llu\n",a.yuan);
    for(i=0;i<a.wei;i++)
    {
        printf("%d",a.shu[i]);
    }
    printf("\nwei=%d\n",a.wei);*/
    return a;

}

/*bigint yihuo(bigint mid,bigint a)
{
    bigint re,i;
    for(i=0;(i<mid.wei)||(i<a.wei);i++)
    {
        re.shu[i]=mid.shu[i]^a.shu[i];
    }
    if(mid.wei>=a.)
}*/

bigint reverse(bigint a)
{
    int i,m;
    for(i=0;i<a.wei;i++)
    {
        m=a.shu[i];
        a.shu[i]=a.shu[a.wei-i-1];
        a.shu[a.wei-i-1]=m;
    }
    return a;
}

bigint jia(bigint a,bigint b)
{
    bigint re;
    memset(re.shu,0,sizeof(int)*30);
    int i,mid,jin=0;
    a=reverse(a);
    b=reverse(b);
    for(i=0;(i<a.wei)||(i<b.wei)||(jin>0);i++)
     {
         mid=a.shu[i]+b.shu[i]+jin;
         re.shu[i]=mid%10;
         jin=mid/10;
     }
     re.wei=i;
     re=reverse(re);
     return re;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    bigint *a=malloc(sizeof(bigint)*n);
    for(i=0;i<n;i++)
    {
        memset(a[i].shu,0,sizeof(int)*30);
        scanf("%s",a[i].s);
        a[i]=zhuan(a[i]);
    }

    qsort(a,n,sizeof(bigint),cmp);

    bigint mid=a[0];
    bigint re;
    memset(re.shu,0,sizeof(int)*30);
    re.yuan=0;
    re.shu[0]=0;
    re.wei=1;

    for(i=1;i<n-1;i++)
    {
        mid.yuan^=a[i].yuan;
    }
    if(mid.yuan!=a[n-1].yuan) printf("-1");
    else
    {
        for(i=0;i<n-1;i++)
        {
            //re+=a[i];
            re=jia(re,a[i]);
        }
        for(i=0;i<re.wei;i++)
        {
            printf("%d",re.shu[i]);
        }
    }
    return 0;
}

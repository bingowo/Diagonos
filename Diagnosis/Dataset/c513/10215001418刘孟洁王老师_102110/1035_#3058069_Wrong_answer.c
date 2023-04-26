#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    long long int r,h,s;
}vol;

long long int max(long long int s[],int n)
{
    int i=0;
    while(i<n)
    {
        if(s[i]>s[i+1])
        {
            s[i+1]=s[i];
            i++;
        }
        else i++;
    }
    return s[i];
}

int cmp1(const void*a,const void*b)
{
    vol c=*(vol*)a;
    vol d=*(vol*)b;
    return d.r-c.r;
}//按照r降序排列

int cmp2(const void*a,const void*b)
{
    vol c=*(vol*)a;
    vol d=*(vol*)b;
    return d.s-c.s;
}//按照s降序排列

int main()
{
    long long int n,m,i,j,k,l,*sss;
    vol *t,*a;
    scanf("%lld%lld",&n,&m);
    t=(vol*)malloc(n*sizeof(vol));
    sss=(long long int*)malloc(n*sizeof(long long int));
    for(i=0;i<n;i++)
        scanf("%lld%lld",&t[i].r,&t[i].h);
    for(i=0;i<n;i++)
        t[i].s=2*t[i].r*t[i].h;
    qsort(t,n,sizeof(t[0]),cmp1);
    for(i=0;i<=n-m;i++)
    {
        a=(vol*)malloc((n-i+1)*sizeof(vol));
        sss[i]=t[i].s+t[i].r*t[i].r;
        for(j=i+1,k=0;j<n;j++,k++)
            a[k]=t[j];
        qsort (a,k,sizeof(vol),cmp2);
        for(l=0;l<m-1;l++)
            sss[i]+=a[l].s;
    }
    printf("%lld\n",max(sss,n-m));
    return 0;
}

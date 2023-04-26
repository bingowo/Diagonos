#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    long long int r,h,S,SS;
}column;

long long int max(long long int s[],int n)
{
    int i = 0;
    while(i<n-1)
    {
        if(s[i]>s[i+1])s[i+1] = s[i],i++;
        else i++;
    }
    return s[i];
}

int cmp(const void*a,const void*b)
{
    column c = *(column*)a;
    column d = *(column*)b;
    if(c.S<d.S)return 1;
    else return -1;
}//按侧面积降序排



int main()
{
    long long int n,m,i,j,k,*SSS;
    column *s,*t;
    scanf("%lld%lld",&n,&m);
    s = (column *)malloc(n*sizeof(column));
    t = (column *)malloc(n*sizeof(column));
    SSS = (long long int *)malloc(n*sizeof(long long int));
    for(i = 0; i < n; i++)scanf("%lld%lld",&s[i].r,&s[i].h);
    for(i = 0; i < n; i++)
        {
            s[i].S = 2 * s[i].r * s[i].h;//求出侧面积；
        }
    memcpy(t,s,sizeof(column)*n);
    qsort(t,n,sizeof(t[0]),cmp);
    qsort(s,n,sizeof(t[0]),cmp);
    for(i = 0; i < n; i++)
    {
        SSS[i] = s[i].r * s[i].r + s[i].S;
        for(j = 0,k = 0; k < m-1; k++,j++)
        {
            if(i != j)SSS[i] = SSS[i] + t[j].S;
                else j++;
            }
    }
    printf("%lld\n",max(SSS,n));
    //for(i = 0; i < n; i++)printf("%lld %lld\n",t[i].r,t[i].h);
     //for(i = 0; i < n; i++)printf("%lld\n",SSS[i]);
    return 0;
}


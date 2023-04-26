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

int cmp1(const void*a,const void*b)
{
    column c = *(column*)a;
    column d = *(column*)b;
    if(c.r<d.r)return 1;
    else return -1;
}//按半径降序排


int cmp2(const void*a,const void*b)
{
    column c = *(column*)a;
    column d = *(column*)b;
    if(c.S<d.r)return 1;
    else return -1;
}//按侧面积降序排

int main()
{
    long long int n,m,i,j,k,l,*SSS;
    column *s,*t;
    scanf("%lld%lld",&n,&m);
    s = (column *)malloc(n*sizeof(column));
    SSS = (long long int *)malloc(n*sizeof(long long int));
    for(i = 0; i < n; i++)scanf("%lld%lld",&s[i].r,&s[i].h);
    for(i = 0; i < n; i++)
        {
            s[i].S = 2 * s[i].r * s[i].h;//求出侧面积；
        }
    qsort(s,n,sizeof(t[0]),cmp1);//先按半径降序
    for(i = 0; i < n-m; i++)
    {
        t = (column *)malloc((n-i)*sizeof(column));
        SSS[i] = s[i].S + s[i].r * s[i].r;
       for(j = i,k = 0; j < n; k++,j++)t[k] = s[j];
       qsort(t,k,sizeof(column),cmp2);//剩下n-i个找侧面积最大的m-1个
       for(l = 0; l < m-1; l++)SSS[i] = SSS[i] + t[l].S;
    }

    printf("%lld\n",max(SSS,n-m));
    //for(i = 0; i < n; i++)printf("%lld %lld\n",t[i].r,t[i].h);
     //for(i = 0; i < n; i++)printf("%lld\n",SSS[i]);
    return 0;
}

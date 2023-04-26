#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
typedef struct{long long int count;char s[30];}dna;

int cmp(const void*a1,const void*a2)
{
    dna a=*(dna*)a1;
    dna b=*(dna*)a2;
    if(a.count!=b.count) {if(a.count>b.count) return 1;else return -1;}
    else if(strcmp(a.s,b.s)>0) return 1;
    else return -1;
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    dna*w;
    w=(dna*)malloc(n*sizeof(dna));
    for(long long int i=0;i<n;i++)
        w[i].count=0;
    char z[30];
    long long int sum=0;
    for(long long int i=0;i<n;i++)
    {
       scanf("%s",w[i].s);
    }
    qsort(w,n,sizeof(dna),strcmp);
    dna*r;
    r=(dna*)malloc(sizeof(dna)*n);
    r[0].s=w[0].s;r[0].count=1;
    sum=1;
    for(int i=1;i<n;i++)
    {if(strcmp(w[i].s,w[i-1].s)!=0) {strcpy(r[sum].s,w[i].s);r[sum].count=1;sum++;}
    else r[sum-1].count++;}
    qsort(r,sum,sizeof(dna),cmp);
    for(long long int i=0;i<sum;i++)
        printf("%s\n",r[i].s);
    return 0;
}
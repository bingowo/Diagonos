#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
typedef struct{long long int count;long long int chang;char s[30];}dna;

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
       scanf("%s",z);
       long long int k=0;
       for(;k<sum;k++)
      {
        if(strlen(z)==w[k].chang)
        {
            int j;
            for(j=0;j<w[k].chang;j++)
            if(z[j]!=w[k].s[j]) break;
        }
        
       }
        if(k==sum) {strcpy(w[sum].s,z);w[sum].count=1;w[sum].chang=strlen(z);sum++;}
     }
    qsort(w,sum,sizeof(dna),cmp);

    for(long long int i=0;i<sum;i++)
        printf("%s\n",w[i].s);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char chain[21];
    int freq;
}DNA;
DNA dna[200000];
DNA dna_new[200000];

int cmp_chain(const void*a,const void*b)
{
    char* str_a=((DNA*)a)->chain;
    char* str_b=((DNA*)b)->chain;
    return strcmp(str_a,str_b);
}
int cmp_freq(const void*a, const void*b)
{
    int int_a=((DNA*)a)->freq;
    int int_b=((DNA*)b)->freq;
    return int_a-int_b;
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",dna[i].chain);
        dna[i].freq=0;
    }
    qsort(dna,N,sizeof(DNA),cmp_chain);
    int l=0,count=1;
    for(int i=1;i<=N;i++)
    {
        if(i==N||strcmp(dna[i-1].chain,dna[i].chain))
        {
            dna_new[l]=dna[i-1];
            dna_new[l].freq=count;
            count=1;
            l++;
        }
        else count++;
    }
    qsort(dna_new,l,sizeof(DNA),cmp_freq);
    for(int i=0;i<l;i++)
    {
        printf("%s\n",dna_new[i].chain);
    }
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <string.h>
struct DNA{
    char chain[21];
    int freq;
};
struct DNA dna[200000];
struct DNA dna_new[200000];


int cmp_chain(const void* a,const void* b){
    char* str_a=((struct DNA*)a)->chain;
    char* str_b=((struct DNA*)b)->chain;
    return strcmp(str_a,str_b);
}

int cmp_freq(const void* a,const void* b){
    int int_a=((struct DNA*)a)->freq;
    int int_b=((struct DNA*)b)->freq;
    return int_a-int_b;
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",dna[i].chain);
        dna[i].freq=0;
    }
    qsort(dna,N,sizeof(struct DNA),cmp_chain);
    int l=0,count=1;
    for(int i=1;i<=N;i++){
        if(i==N||strcmp(dna[i-1].chain,dna[i].chain)){
            dna_new[l]=dna[i-1];
            dna_new[l].freq=count;
            count=1;
            l++;
        }
        else count++;
    }
    qsort(dna_new,l,sizeof(struct DNA),cmp_freq);
    for(int i=0;i<l;i++){
        printf("%s\n",dna_new[i].chain);
    }
    return 0;
}

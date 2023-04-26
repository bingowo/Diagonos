#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 21

typedef struct
{
    char code[L];
    int repeat;
}DNA;

int cmp1(const void*a,const void*b)
{
    return strcmp(*(char(*)[L])a,*(char(*)[L])b);
}

int cmp2(const void*a,const void*b)
{
    DNA*st1,*st2;
    st1 = (DNA*)a,st2 = (DNA*)b;
    if(st1->repeat != st2->repeat)
        return st1->repeat - st2->repeat;
    else
        return strcmp(st1->code,st2->code);
}

int main()
{
    int n,i,cnt = 0;
    scanf("%d",&n);
    char input[n][L];
    DNA dna[n];
    for(i = 0;i < n;i++)
    {
        scanf("%s",input[i]);
        dna[i].repeat = 0;
    }
    qsort(input,n,sizeof(input[0]),cmp1);
    strcpy(dna[0].code,input[0]);
    dna[0].repeat++;
    for(i = 1;i < n;i++)
    {
        if(strcmp(input[i],input[i - 1]) == 0)
            dna[cnt].repeat++;
        else
        {
            cnt++;
            strcpy(dna[cnt].code,input[i]);
            dna[cnt].repeat++;
        }
    }
    cnt++;
    qsort(dna,cnt,sizeof(dna[0]),cmp2);
    for(i = 0;i < cnt;i++)
    {
        printf("%s\n",dna[i].code);
    }
    return 0;
}

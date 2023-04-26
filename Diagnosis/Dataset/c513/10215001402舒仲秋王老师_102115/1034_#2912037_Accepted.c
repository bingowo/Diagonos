#include <stdio.h>
#include <stdlib.h>
#include<string.h>

double base[26];

int cmp(const void* a,const void* b)
{
    char d1,d2;
    int t;
    d1=*((char*)a),d2=*((char*)b);
    if(d1<'a') d1+=32;
    if(d2<'a') d2+=32;
    if(base[d1-'a']!=base[d2-'a'])
    {
        if(base[d1-'a']>base[d2-'a']) t=-1;
        else t=1;
    }
    else if(d1!=d2) t=*((char*)a)-*((char*)b);
    else t=*((char*)b)-*((char*)a);
    return t;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int j;
        for(j=0;j<26;j++) scanf("%lf",&base[j]);
        char str[200];
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
    return 0;
}

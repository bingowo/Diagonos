#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int index;
    double cnt;
}FRE;

double lfabs(double a)
{
    if(a<0) return -a;
    else return a;
}
int cmp(const void* a, const void* b)
{
    if( lfabs((((FRE*)a)->cnt-((FRE*)b)->cnt)) <= 10e-8) return ((FRE*)a)->index - ((FRE*)b)->index;
    return (((FRE*)a)->cnt - ((FRE*)b)->cnt)>10e-8 ? -1:1;
}



int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        int i;
        FRE fre[26];
        for(i=0;i<26;i++) 
        {
            scanf("%lf",&fre[i].cnt);
            fre[i].index=i;
        }
        qsort(fre,26,sizeof(fre[0]),cmp);
        
        char input[110]={'\0'};
        scanf("%s",&input);
        int cnt[130]={0};
        for(i=0;i<strlen(input);i++) cnt[input[i]]++;
        
        printf("case #%d:\n",t);
        for(i=0;i<26;i++)
        {
            int j;
            for(j=0;j<cnt[fre[i].index+'a'];j++) printf("%c",fre[i].index+'a');
            for(j=0;j<cnt[fre[i].index+'A'];j++) printf("%c",fre[i].index+'A');
        }
        printf("\n");
        t++;
    }
    return 0;
}
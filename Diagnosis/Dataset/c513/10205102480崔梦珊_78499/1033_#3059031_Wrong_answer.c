#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct MAYA
{
    int day;
    int month;
    char str[8];
    int year;
};

int cmp(const void* a,const void* b)
{
    struct MAYA* x=(struct MAYA*)a;
    struct MAYA* y=(struct MAYA*)b;
    if(x->year==y->year)
    {
        if(x->month==y->month)
        {
            return x->day-y->day;
        }
        return x->month-y->month;
    }
    return x->year==y->year;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        struct MAYA ans[10001];
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<8;k++)
            {
                ans[j].str[k]='\0';
            }
        }
        for(int j=0;j<N;j++)
        {
            scanf("%d.",&ans[j].day);
            char s[9];
            scanf("%s",ans[j].str);
            if(ans[j].str[0]=='p'&&ans[j].str[1]=='o') ans[j].month=1;
            if(ans[j].str[0]=='n'&&ans[j].str[1]=='o') ans[j].month=2;
            if(ans[j].str[0]=='z'&&ans[j].str[1]=='i') ans[j].month=3;
            if(ans[j].str[0]=='z'&&ans[j].str[1]=='o') ans[j].month=4;
            if(ans[j].str[0]=='t'&&ans[j].str[1]=='z') ans[j].month=5;
            if(ans[j].str[0]=='x'&&ans[j].str[1]=='u') ans[j].month=6;
            if(ans[j].str[0]=='y'&&ans[j].str[1]=='o') ans[j].month=7;
            if(ans[j].str[0]=='m'&&ans[j].str[1]=='o') ans[j].month=8;
            if(ans[j].str[0]=='c'&&ans[j].str[1]=='h') ans[j].month=9;
            if(ans[j].str[0]=='y'&&ans[j].str[1]=='a') ans[j].month=10;
            if(ans[j].str[0]=='z'&&ans[j].str[1]=='a') ans[j].month=11;
            if(ans[j].str[0]=='c'&&ans[j].str[1]=='e') ans[j].month=12;
            if(ans[j].str[0]=='m'&&ans[j].str[1]=='a') ans[j].month=13;
            if(ans[j].str[0]=='k'&&ans[j].str[1]=='a') ans[j].month=14;
            if(ans[j].str[0]=='m'&&ans[j].str[1]=='u') ans[j].month=15;
            if(ans[j].str[0]=='p'&&ans[j].str[1]=='a') ans[j].month=16;
            if(ans[j].str[0]=='k'&&ans[j].str[1]=='o') ans[j].month=17;
            if(ans[j].str[0]=='c'&&ans[j].str[1]=='u') ans[j].month=18;
            if(ans[j].str[0]=='u'&&ans[j].str[1]=='a') ans[j].month=19;
            scanf("%d\n",&ans[j].year);
        }
        qsort(ans,N,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            printf("%d. %s %d\n",ans[j].day,ans[j].str,ans[j].year);
        }
    }

}

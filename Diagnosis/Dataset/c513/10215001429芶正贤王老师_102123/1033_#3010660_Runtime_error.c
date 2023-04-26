#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int date;
    char MON[10];
    int month;
    int year;
}DATA;

int cmp(const void*a , const void*b)
{ //升序year , month , date
    DATA*x = (DATA*)a;
    DATA*y = (DATA*)b;
    if(x->year != y->year)
        return(x->year - y->year);
    else
    {
        if(x->month != y->month)
            return(x->month - y->month);
        else
            return(x->date - y->date);
    }
}

int main()
{
    int T;
    scanf("%d",&T);              //问题数
    int index;
    for(index = 0;index < T;index++)     //进入一个问题
    {
        int N;
        scanf("%d",&N);         //数据个数
        DATA CASE[N];
        int i;
        for(i=0;i<N;i++)         //第一个数据
        {
            char d[5];
            scanf("%s",d);
            int len;
            char mon[10];
            len = strlen(d);
            if(len == 2)  //<=10
                CASE[i].date = (d[0] - '0' );
            else           //>10
                CASE[i].date = 10 + (d[1] - '0');
            scanf("%s",CASE[i].MON);
            strcpy(mon,CASE[i].MON);
            
            if(strcmp(mon,"pop") == 0)
                CASE[i].month = 1;
            else if(strcmp(mon,"no") == 0)
                CASE[i].month = 2;
            else if(strcmp(mon,"zip") == 0)
                CASE[i].month = 3;
            else if(strcmp(mon,"zotz") == 0)
                CASE[i].month = 4;
            else if(strcmp(mon,"tzec") == 0)
                CASE[i].month = 5;
            else if(strcmp(mon,"xul") == 0)
                CASE[i].month = 6;
            else if(strcmp(mon,"yoxkin") == 0)
                CASE[i].month = 7;
            else if(strcmp(mon,"mol") == 0)
                CASE[i].month = 8;
            else if(strcmp(mon,"chen") == 0)
                CASE[i].month = 9;
            else if(strcmp(mon,"yax") == 0)
                CASE[i].month = 10;
            else if(strcmp(mon,"zac") == 0)
                CASE[i].month = 11;
            else if(strcmp(mon,"ceh") == 0)
                CASE[i].month = 12;
            else if(strcmp(mon,"mac") == 0)
                CASE[i].month = 13;
            else if(strcmp(mon,"kankin") == 0)
                CASE[i].month = 14;
            else if(strcmp(mon,"muan") == 0)
                CASE[i].month = 15;
            else if(strcmp(mon,"pax") == 0)
                CASE[i].month = 16;
            else if(strcmp(mon,"koyab") == 0)
                CASE[i].month = 17;
            else if(strcmp(mon,"cumhu") == 0)
                CASE[i].month = 18;
            else if(strcmp(mon,"uayet") == 0)
                CASE[i].month = 19;
            
            scanf("%d",CASE[i].year);
            
        }
        qsort(CASE , N ,sizeof(DATA) , cmp);
        printf("case #%d:\n",index);
        int j;
        for(j=0;j<N;j++)
        {
            printf("%d. ",CASE[j].date);
            printf("%s ",CASE[j].MON);
            printf("%d\n",CASE[j].year);
        }
        
    }
    return 0;
}
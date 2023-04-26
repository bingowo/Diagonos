#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

double freq[26];

int cmp(const void*a,const void*b)
{
    char*p1 = (char*)a;
    char*p2 = (char*)b;
    if((*p1 == *p2+32)||(*p2 == *p1+32))
    {
        if(*p1<*p2)
        {
            return 1;
        }
        else{return -1;}
    }
    char p3 = toupper(*p1);
    char p4 = toupper(*p2);

    if(freq[p3-65]>=freq[p4-65])
    {
        return -1;
    }
    else{return 1;}
}

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i = 0;i<T;i++)
    {
        for(int j = 0;j<26;j++)
        {
            scanf("%lf",&freq[j]);
        }
        getchar();
        char c[100] = {'\0'};
        int count = 0;
        while((c[count] = getchar())!='\n')
        {
            count++;
        }
        qsort(c,count,sizeof(char),cmp);
        printf("case #%d:\n",i);
        for(int cou = 0;cou<count;cou++)
        {
            printf("%c",c[cou]);
        }
        printf("\n");
    }
    return 0;
}

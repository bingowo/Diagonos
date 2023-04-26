#include <stdio.h>
#include <stdlib.h>

typedef struct RECORD
{
    int x;
    char m[31];
} node;

int cmp(const void* a,const void* b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    return p1.x - p2.x;
}

int Num(char* str)
{
    int len,i,sum = 0, flag = 0;
    len = strlen(str);
    for (i = 0; i < len; i++)
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum = 10*sum +str[i]-48;
            flag = 1;
        }
    if (flag == 0) sum = -1;
    return sum;
}


int main()
{
    node s[100];
    int i=0;
    while(scanf("%s",s[i].m)!=EOF)
    {
        i++;
        s[i].x=Num(s[i].m);

    }
    qsort(s,i,sizeof(s[0]),cmp);

    for (int j=0; j<i-1; j++)
    {
        printf("%s ",s[j].m);
    }
    printf("%s\n", s[i-1].m);
    return 0;
}

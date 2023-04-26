#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//用于判断是否有数字。若有，返回数字本身；若无，返回-1
int judge(char*a)
{
    char* q = a;
    int i;
    int sum = 0;
    for(i = 0; i < strlen(a);i++)
    {
        if(*q++>=  '0'&& *q++<= '9')
            break;
    }
    if(i == strlen(a))
        return -1;
    else
        for(;i < strlen(a);i++)
        {
            if(*q++>= '0'&& *q++<= '9')
                {
                    sum = sum*10 + (*q - '0');
                }
                else
                    break;
        }
    return sum;


}

//比较
int cmd(void*a,void*b)
{
    char*A = *(char**)a;
    char*B = *(char**)b;
    if(judge(A) != judge(B))
    {
        return judge(A) >  judge(B);
    }
    else
    {
        return strcmp(A,B);
    }
}


int main()
{
    char s[1000][32];
    int i =0;
    while(scanf("%s",s[i++]) !=EOF);
    qsort(s,i - 1,sizeof(char a[32]),cmd);
    for(int j = 0;j < i - 1;j++)
    {
        printf("%s ",s[j]);
    }

    return 0;
}
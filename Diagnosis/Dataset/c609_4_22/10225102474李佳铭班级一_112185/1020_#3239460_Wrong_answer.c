#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct{
    char a[35];
}S;

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
int cmd(const void*a,const void*b)
{
    S* A = (S*)a;
    S* B = (S*)b;
    if(judge(A->a) != judge(B->a))
    {
        return judge(A->a) >  judge(B->a);
    }
    else
    {
        return strcmp(A->a,B->a);
    }
}


int main()
{
    S s[100];
    int i =0;
    while(scanf("%s",s[i].a) !=EOF) i++;
    qsort(s,i-1,sizeof(S),cmd);
    for(int j = 0;j < i - 1;j++)
    {
        printf("%s ",s[j].a);
    }
    return 0;
}
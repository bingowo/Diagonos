#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//用于判断是否有数字。若有，返回数字本身；若无，返回-1
int judge(char*a)
{
    char* q = a;
    int i;
    int sum = 0;
    int length = strlen(a);
    for(i = 0; i < length;i++)
    {
        if(*q >=  '0'&& *q <= '9')
            break;
        q++;
    }
    if(i == strlen(a))
        return -1;
    else
        for(;i < length;i++)
        {
            if(*q >= '0'&& *q <= '9')
                {
                    sum = sum*10 + (*q - '0');
                }
                else
                    break;
            q++;
        }
    return sum;


}

//比较
int cmd(const void*a,const void*b)
{
    char*A = (char*)a;
    char*B = (char*)b;
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
    while(scanf("%s",&s[i++]) !=EOF);
    qsort(s,i - 1,sizeof(s[0]),cmd);
    for(int j = 0;j < i - 1;j++)
    {
        printf("%s ",s[j]);
    }

    return 0;
}

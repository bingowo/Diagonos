#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number(char* str)//返回字符串中的数字
{
    int len = strlen(str);
    int sum = 0, flag = 0, i;
    for( i = 0 ; i < len ; i++)
    {
        if(str[i] >= '0' && str[i] <= '9' )
        {
            sum = sum * 10 + str[i] - '0';
            flag = 1;
        }
    }
    if(flag == 0)
        sum = -1;
    return sum;
}

int cmp( const void *a, const void *b )
{
    char *str1, *str2;
    str1 = (char *)a;
    str2 = (char *)b;
    int s1 = number(str1), s2 = number(str2);
    if(s1 == s2)
        return strcmp(str1,str2);
    else
        return s1 < s2 ? -1 : 1;
}

int main()
{
    char str[200][50];
    int count = 0, i;
    while(scanf("%s",str[count]) != EOF)
        count++;

    qsort(str,count,sizeof(char),cmp);

    for( i = 0 ; i < count-1 ; i++)
        printf("%s ",str[i]);
    printf("%s\n",str[i]);
}

#include <stdio.h>
#include <stdlib.h>

int number(char* str)
{
    int len, i, sum = 0, flag = 0;
    len = strlen(str);
    for (i = 0; i < len; i++)
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum = 10*sum + str[i]-48;
            flag = 1;
        }
    if (flag == 0) sum = -1;
    return sum;
}

int cmp(const void* a, const void* b)
{
    int s1,s2;
    char* str1, *str2;
    str1 = (char*)a;
    str2 = (char*)b;
    s1 = number(str1);
    s2 = number(str2);
    if(s1 == s2) return strcmp(str1, str2);
    else
    {
        if(s1 > s2) return 1;
        else return -1;
    }
}

int main()
{
    char s[100][31];
    int i=0;
    while(scanf("%s",s[i])!=EOF)
    {
        i++;
    }

    qsort(s,i,sizeof(s[0]),cmp);

    for (int j=0;j<i-1;j++)
        printf("%s",s[j]);
    printf("%s\n",s[i-1]);

    return 0;
}

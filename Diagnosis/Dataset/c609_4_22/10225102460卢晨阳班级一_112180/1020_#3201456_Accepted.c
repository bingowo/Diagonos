#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num(char *str);
int cmp(const void* a, const void* b)
{
    int s1, s2;
    char* str1, *str2;
    str1 = (char*) a;	str2 = (char*) b;
    s1 = num(str1);
    s2 = num(str2);
    if (s1 == s2)
        return strcmp(str1, str2);
    else
    {
        if (s1 > s2)
            return 1;
        else
            return -1;
    }
}

int num(char *str)
{
    int len, i, sum = 0, flag = 0;
    len = strlen(str);
    for(i = 0;i < len; ++i)
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum = 10 * sum + str[i] - 48;
            flag = 1;
        }
    if (flag == 0)
        sum = -1;
    return sum;
}
int main()
{
	char str[110][40];
	int count = 0;
	while (scanf("%s", str[count]) != -1)
	{
    	count++;
	}
	qsort(str, count, sizeof(str[0]),cmp);
	int i;
	for (i = 0; i < count; ++i)
    printf("%s ", str[i]);
	return 0;
}
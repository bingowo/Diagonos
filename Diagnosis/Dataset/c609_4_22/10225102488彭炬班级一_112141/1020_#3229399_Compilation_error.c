#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getnumber(char *p)
{
    int i,number = 0,flag = 0;
    int len = strlen(p);
    for(i = 0;i < len;i++)
    {
        if(*(p+i)<='9'&&*(p+i)>='0')
        {
            flag = 1;
            number = number * 10 + *(p+i) - '0';
        }
    }
    if(flag == 0)
        number = -1;
    return number;
}

int cmp(const void *a,const void *b)
{
    char *p1,*p2;
    p1 = (char *)a;
    p2 = (char *)b;
    int n1 = getnumber(p1);
    int n2 = getnumber(p2);
    if(n1 == n2)
        return strcmp(p1,p2);
    else
        return n1 - n2;
}

int main()
{
    char str[100][31];
    int i = 0;
    while(scanf("%s",s[i])!=EOF)
        i++;
    qsort(str,i,sizeof(str[0]),cmp);
    for(int j = 0;j <= i;j++)
        printf("%s ",str[j]);
    return 0;
}

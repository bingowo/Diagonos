#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int Turn(char *p)
{
    int x = 0,i,y = 1;
    for(i = strlen(p)-1;i>=0;i--)
{
     if(p[i]>='0'&&p[i]<='9')
        {
            x = x+(p[i]-'0')*y;
            y*=10;
        }
}
    return x;
}
int cmp(const void*a,const void*b)
{
    char*p1 = *(char**)a;
    char*p2 = *(char**)b;
    int n = Turn(p1)-Turn(p2);
    return n?n:strcmp(p1,p2);
}
int main()
{
    char *s[100];
    int i,j;
    for(i = 0;i<100;i++)
        s[i] = (char*)malloc(31*sizeof(char));

    for(i = 0;scanf("%s",s[i])!=EOF;i++);

    qsort(s,i,sizeof(s[0]),cmp);

    for(j = 0;j<i;j++)
        printf("%s ",s[j]);
    for(i =0;i<100;i++)
        free(s[i]);
    return 0;
}

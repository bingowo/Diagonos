#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void *b)
{
    return *((int*)b)-*((int*)a);
}
int Num(char s[51])
{
    int i,j,n = 1;
    int a[61];
    a[0] = 1;
    for(i = 0,j = 1;i<strlen(s)-1;i++)
    {
        if(s[i]==s[i+1])
        {
            a[j] = n;
            j++;
            n = 1;
        }
        else n++;
    }
    a[j] = n;
    qsort(a,j+1,sizeof(a[0]),cmp);
    return a[0];
}
int main()
{
    char s[51];
    scanf("%s",s);
    printf("%d",Num(s));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100][31];
    int n=0;
    while (scanf("%s",s[n])!=EOF)
        n++;
    int number(char *a)
    {
        int sum=0,flag=0,len=strlen(a);
        for (int i=0;i<len;i++)
        {
            if (a[i]>='0'&&a[i]<='9') sum=sum*10+a[i]-48;
            flag=1;
        }
        if (flag==0) sum=-1;
        return sum;
    }
    int cmp(const void *a,const void *b)
{
    char *a1,*b1;
    a1=*(char (*)[31])a;b1=*(char (*)[31])b;
    int numbera=number(a1),numberb=number(b1);
    if (numbera!=numberb) return numbera-numberb;
    else return strcmp(a1,b1);
}
    qsort(s,n,sizeof(s[0]),cmp);
    for (int i=0;i<n;i++)
        printf("%s%c",s[i],i==n-1?'\n':' ');
    return 0;
}

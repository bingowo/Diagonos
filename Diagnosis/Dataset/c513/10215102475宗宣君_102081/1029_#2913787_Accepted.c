#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    char m,n;
    m = *(char*)a;n = *(char*)b;
    if(m>n) return 1;
    else return -1;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    char s[201],a[201];
    for(i = 0;i<T;i++)
    {
        gets(s);
        int j = 0,m = 0;
        while(s[j]!='\0')
        {
            if(s[j]>=65&&s[j]<=90) {a[m] = s[j];m++;}
            j++;
        }
        a[m] = '\0';
        qsort(a,m,sizeof(char),cmp);
        j = 0;m = 0;
        printf("case #%d:\n",i);
        while(s[j]!='\0')
        {
            if(s[j]>=65&&s[j]<=90) {printf("%c",a[m]);m++;}
            else printf("%c",s[j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}

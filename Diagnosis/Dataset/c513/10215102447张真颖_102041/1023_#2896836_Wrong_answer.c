#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number(char *s)
{
    int n=0,flag=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9') n=n*10+s[i]-'0',flag=1;
    }
    if(flag==0) return -1;
    else return n;
}

int strnumcmp(const void*a,const void*b)
{
    char *pa=*(char(*)[31])a,*pb=*(char(*)[31])b;
    int n1=number(pa),n2=number(pb);
    if((n1*n2<0 ||(n1>0&&n2>0))&&n1!=n2)
        return n1-n2;
    else return strcmp(pa,pb);
    return 0;
}

int main()
{
    char s[101][31]={};
    int count=0;
    while(scanf("%s",s[count])!=EOF) count++;
    qsort(s,count,sizeof(s[0]),strnumcmp);
    for(int i=0;i<count;i++)
        printf("%s%c",s[i],i==count-1?'\n':' ');
    return 0;
}

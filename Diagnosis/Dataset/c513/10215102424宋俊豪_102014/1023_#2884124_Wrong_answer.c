
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

int num1(char *s)
{
    int sum=0,flag=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
        if(s[i]>='0'&&s[i]<='9')
    {
        sum=10*sum+s[i]-'0';
        flag=1;
    }
    if (flag==0)
        sum=-1;
    else
        return sum;
}
int cmp(const void *a,const void *b)
{
    int n1,n2;
    char *s1,*s2;
    s1=*(char(*)[31])a;s2=*(char(*)[31])b;
    n1=num1(s1);
    n2=num1(s2);
    if (n1==n2)
        return strcmp(s1,s2);
    else
      return (n1-n2);
}
int main()
{
    char s[31][101];
    int cnt=0;
    while(scanf("%s",s[cnt])!=EOF)
        cnt++;
    qsort(s,cnt,sizeof(s[0]),cmp);
    for(int i=0;i<cnt;i++)
    printf("%s%c",s[i],i==cnt-1?'\n':' ');
}

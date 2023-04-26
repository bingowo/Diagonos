#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 102
#define n 32
int number(char* s)
{
    int i=0;
    int num=0;
    int flag=0;
    for(i=0;s[i];i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        num=num*10+s[i]-'0';
        flag=1;
    }
    if(flag==0)
    num=-1;
    return -1;
}
int strnumcmp(const void* e1,const void* e2)
{
    char* s1;char *s2;
    int num1,num2;
    s1=(char*)e1;
    s2=(char*)e2;
    num1=number(s1);
    num2=number(s2);
    if(num1==num2)
    return strcmp(s1,s2);
    else
    {
        if(num1>num2)
        return 1;
        else
        return -1;
    }
}
int main()
{
    char s[N][n];
    int count=0;
    while(scanf("%s",s[count])==1)
    count++;
    qsort(s,count,sizeof(s[0]),strnumcmp);
    for(int i=0;i<count-1;i++)
    printf("%s ",s[i]);
    printf("%s\n",s[count-1]);
}
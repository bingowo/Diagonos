#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int number(char* s)
{
    int len=strlen(s),flag=o,sum=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum=sum*10+s[i]-'0';
            flag=1;
        }
    }
    if(flag==0) sum=-1;
    return sum;
}
int strnumcmp(const void*a,const void*b)
{
    char *ch1,*ch2;
    int s1,s2;
    ch1=(char*)a;
    ch2=(char*)b;
    s1=number(ch1);
    s2=number(ch2);
    if(s1==s2) return strcmp(ch1,ch2);
    else
    {
        if(s1>s2) return 1;
        else return-1;
    }
}
int main()
{
    char s[101][31];
    int count=0,i;
    while(scanf("%s",s[count])!=EOF) count++;
    qsort(s,count,sizeof(s[0]),strnumcmp);
    for(i=0;i<count-1;i++) printf("%s\n",s[i]);
    return 0;
}
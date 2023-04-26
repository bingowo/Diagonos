#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getnum(char *s)
{
    int sum=0,flag=0;
    long long int len=strlen(s);
    for(long long i=0;i<len;i++)
        if(s[i]>='0'&&s[i]<='9')//提取数字
    {
        sum=10*sum+s[i]-48;
        flag=1;
    }
    if(flag==0) sum=-1;
    return sum;
}

int strnumcmp(const void *q1,const void *q2)
{
    int num1,num2;
    char *s1,*s2;

    s1=*(char(*)[31])q1;
    s2=*(char(*)[31])q2;

    num1=getnum(s1);
    num2=getnum(s2);

    if(num1==num2)
        return strcmp(s1,s2);
    else
        return num1-num2;
}

int main()
{
    long long cnt=0;    char a[110][31];
    while(scanf("%s",a[cnt])!=EOF) cnt++;

    qsort(a,cnt,sizeof(a[0]),strnumcmp);

    for(long long i=0;i<cnt;i++)
		printf("%s%c",a[i],i==cnt-1?'\n':' ');

    return 0;
}
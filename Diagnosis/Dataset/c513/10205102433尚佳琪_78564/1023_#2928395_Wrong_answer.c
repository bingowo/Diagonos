#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int strnumcmp(const void *a,const void *b)
{
    char *s1,*s2;
    s1=(char *)a;
    s2=(char *)b;
    int len1=0,len2=0,num1=0,num2=0;
    len1=strlen(s1);
    len2=strlen(s2);
    for(int i=0;i<len1;i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
            num1=num1*10+s1[i]-'0';
    }
    for(int i=0;i<len2;i++)
    {
        if(s2[i]>='0'&&s2[i]<='9')
            num2=num2*10+s2[i]-'0';
    }
    if(num1==num2)
    {
       // printf("%d %d\n",num1,num2);
        return strcmp(s1,s2);
    }
    else
        return num1-num2;

}
int main()
{
    char s[105][50];
    int i=0;
    while(scanf("%s",s[i])!=EOF)
    {
        i++;
    }
    qsort(s,i,sizeof(s[0]),strnumcmp);
    for(int j=0;j<i;j++)
        printf("%s ",s[j]);
}

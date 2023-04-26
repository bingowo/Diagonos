#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char *s1,*s2;
    s1=(char*)a;
    s2=(char*)b;
    int sign1=1;
    int sign2=1;
    if(*s1=='-')
    {
        sign1 = -1,s1++;
    }
    else if(*s1=='+') s1++;     //s1指向最高位数字
    if(*s2=='-') sign2 = -1,s2++;
    else if(*s2=='+') s2++;
    if(sign1 != sign2)
        return sign1-sign2; //符号不同

    char *p1,*p2;
    for(p1=s1;*p1 && *p1!='.';p1++); //定位小数点
    for(p2=s2;*p2 && *p2!='.';p2++);

    int len1 = p1-s1;  //整数部分长度
    int len2 = p2-s2;
    if(len1 != len2)
        return sign1*(len1-len2);

    return sign1*strcmp(s1,s2);
}
int main()
{
    int n;
    char s[100][101];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",s[i]);
    }
    return 0;
}

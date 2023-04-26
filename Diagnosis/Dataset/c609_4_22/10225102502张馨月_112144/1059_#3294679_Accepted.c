#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char *s1, *s2; //处理符号
    s1=(char*)a;
    s2=(char*)b;
    int sign1=1,sign2=1;
    if(s1[0]=='+') s1++;  //指针可以移动
    else if(s1[0]=='-') {s1++;sign1=-1;}
    if(s2[0]=='+') s2++;
    else if(s2[0]=='-') {s2++;sign2=-1;}
    if(sign1!=sign2) //一正一负
        return sign1-sign2;

    char *p1,*p2;// 处理小数点
    p1=(char*)a;
    p2=(char*)b;
    for(p1=s1;*p1 && *p1!='.';p1++);
    for(p2=s2;*p2 && *p2!='.';p2++);

    //整数长度
    int len1=p1-s1;
    int len2=p2-s2;

    if(len1!=len2)
        return sign1*(len1-len2);
    else return sign1*strcmp(s1,s2);



}

int main()
{
    char s[100][101];
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
    {
        scanf("%s",&s[i]);
    }
    qsort(s,t,sizeof(s[0]),cmp);
    for(int k=0;k<t;k++)
        printf("%s\n",s[k]);
    return 0;
}

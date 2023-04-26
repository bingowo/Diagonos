#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp (const void* a,const void* b)
{
    char*a1=(char*)a,*b1=(char*)b;
    return strcmp(a1,b1);
}
int cmp1 (const void*a,const void*b)
{
    char*a1=(char*)a,*b1=(char*)b;
    int sa=0,sb=0;
    for(int i = 0 ;i < strlen(a1);i++)
        if(a1[i]>='0'&&a1[i]<='9')sa=sa*10+a1[i]-'0';
     for(int i = 0 ;i < strlen(b1);i++)
        if(b1[i]>='0'&&b1[i]<='9')sb=sb*10+b1[i]-'0';
    if (sa>sb) return 1;
    else if(sa<sb) return -1;
    else return strcmp(a1,b1);
}
int main()
{
    char s[100][31];
    char s1[100][31];
    char s2[31];
    int num1=0,num2=0;
    while (scanf("%s",s2)!=EOF){
//
        int find=0;
        for (int i=0;i<strlen(s2);i++)
        if (s2[i]>='0'&&s2[i]<='9') {find++;break;}
        if (find>0) strcpy(s1[num2++],s2);
        else strcpy(s[num1++],s2);

    }
    qsort(s,num1,sizeof(s[0]),cmp);
    qsort(s1,num2,sizeof(s1[0]),cmp1);
    for (int i=0;i<num1-1;i++) printf("%s ",s[i]);
    if (num1>=1)printf("%s",s[num1-1]);
    if(num2>0&&num1!=0) printf(" ");
    for (int i=0;i<num2-1;i++) printf("%s ",s1[i]);
    if (num2>=1) printf("%s",s1[num2-1]);
    printf("\n");
    return 0;
}

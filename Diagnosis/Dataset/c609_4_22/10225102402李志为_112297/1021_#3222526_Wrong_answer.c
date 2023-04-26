#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char xu[26];
typedef struct
{
    char s[1000];
    char w[100][20];
} N;
int strcmp0(char*a,char*b,char*c)
{
    char c1,c2;
    int t1=0,t2=0;
    do
    {
        c1=*(b++);
        c2=*(c++);
        if(c1=='\0') t1=-1;
        if(c2=='\0') t2=-1;
    }
    while(c1==c2);
    for(int x=0;x<26;x++){
        if(c1==a[x]) t1=x;
        if(c2==a[x]) t2=x;
    }
    return t1-t2;

}
int cmp(const void*a,const void*b)
{
    return strcmp0(xu,(char*)a,(char*)b);
}
int main()
{
    int i=0,t=0,num=0,n=0;//n代表上一个j
    N p[100];

    while(scanf("%s",xu)!=EOF){
        gets(p[i].s);
        num=0;
        for(int j=0,n=0;j<strlen(p[i].s);j++){
            if(p[i].s[j]==' '){
                t=j-n;//记住n代表上一个j，t代表复制数量
                strncpy(p[i].w[num],p[i].s+n,t);
                num++;
                n=j;
            }
            if(j==strlen(p[i].s)-1) {
                strncpy(p[i].w[num],p[i].s+n,j-n);
                num++;
            }
        }//这个循环就是记下来字符串
        qsort(p[i].w,num,sizeof(p[i].w[0]),cmp);
        for(int j=0;j<num;j++){
            printf("%s ",p[i].w[j]);
        }
        i++;
    }
    return 0;
}
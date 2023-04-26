#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char xu[26];
int strcmp0(const char*a,const char*b,const char*c)
{
    char c1,c2;
    char* y1=b;
    char* y2=c;
    int t1=0,t2=0;
    do
    {
        c1=*(y1++);
        c2=*(y2++);
        if(c1=='\0') t1=-1;
        if(c2=='\0') t2=-1;
    }
    while(c1==c2);
    for(int x=0;x<26;x++){
        if(c1==a[x]) t1=x;
        else if(c1-32==a[x]) t1=x;
        if(c2==a[x]) t2=x;
        else if(c2-32==a[x]) t2=x;
    }
    return t1-t2;

}
int cmp(const void*a,const void*b)
{
    return strcmp0(xu,(char*)a,(char*)b);
}
int main()
{
    char s[2000];
    char w[100][20] ={0};
    int i=0,t=0,num=0,n=0;//n代表上一个j

    while(scanf("%s\n",xu)!=EOF){
        gets(s);
        num=0;
        n=0;
        for(int j=0;j<strlen(s);j++){
            if(s[j]==' ' && num==0){
                t=j;//记住n代表上一个j，t代表复制数量
                strncpy(w[num],s+n,t);
                num++;
                n=j;
            }
            else if(s[j]==' '){
                t=j-n-1;
                strncpy(w[num],s+n+1,t);
                num++;
                n=j;
            }
            if(j==strlen(s)-1) {
                strncpy(w[num],s+n+1,strlen(s)-n);
                num++;
            }
        }//这个循环就是记下来字符串
        qsort(w,num,sizeof(w[0]),cmp);
        for(int j=0;j<num;j++){
            printf("%s ",w[j]);
        }
        printf("\n");
        i++;
    }
    return 0;
}
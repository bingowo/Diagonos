#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int judge(int n)
{
    char s1[25],s2[25];
    int c=n,i=0;
    do{
        s1[i++]=c%10+48;
        c/=10;
    }while(c>0);
    for(int m=0;m<strlen(s1);m++){
        s2[m]=s1[strlen(s1)-m-1];
    }
    if(strcmp(s1,s2)==0)return 1;
    else return 0;
}
int add(int n)
{
    char s1[100],s2[100];
    int c=n,res=0,n1=0,i=0;
    do{
        s1[i++]=c%10+48;
        c/=10;
    }while(c>0);
    n1=atoi(s1);
    res=n1+n;
    return res;
}
int main()
{
    int n;scanf("%d",&n);
    int step=0;
    while(judge(n)!=1){
        step++;
        n=add(n);
    }
    printf("%d %d",step,n);
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int num(char *str)
{
    int len,sum=0,flag=0;
    len = strlen(str);
    for(int i=0;i<len;i++)
    if(str[i]>='0'&&str[i]<='9'){
        sum=10*sum+str[i]-48;
        flag=1;
    }
    if (flag==0)sum=-1;
    return sum;
}
int cmp(const void *a,const void *b)
{
    int n1,n2;
    char *a1=(char*)a;char *b1=(char*)b;
    n1=num(a1);n2=num(b1);
    if(n1==n2)return strcmp(a1,b1);
    else return n1>n2?1:-1;
}
int main()
{
    char str[100][31];
    int i=0;
    while(scanf("%s",str[i])!=EOF)i++;
    qsort(str,i,sizeof(str[0]),cmp);
    for(int step=0;step<i;step++)printf("%s ",str[step]);
    return 0;
}

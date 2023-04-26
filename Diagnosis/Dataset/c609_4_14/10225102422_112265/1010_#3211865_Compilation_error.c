#include<stdio.h>
#include<stdlib.h>
#define N 50;
int main()
{
    int n;
    scanf("%d",&n);
    int num;
    scanf("%d",&num);
    char s[N];
    int i=0;int y=0;
    for(i=0;n!=0;n=n/num,i++)
    {
        y=n%num;
        if(y<=9)
        s[i]='0'+y;
        else if(y>9)
        s[i]='A'+y-10;
    }
    int j;
    for(j=i-1;j>=0;j--)
    printf("%c",s[j]);
}
#include<stdio.h>
#include<stdlib.h>
#define N 50
int main()
{
    int n;
    scanf("%d",&n);
    int num;
    scanf("%d",&num);
    char s[N];
    int i=0;int y=0;
    int num1,n1;
    while(n!=0)
    {
        if(n<0) n1=-n;
        else n1=n;
        if(num<0)num1=-num;
        else num1=num;
        y=n1%num1;
        if(y<=9)
        s[i]='0'+y;
        else 
        s[i]='A'+y-10;
        i++;
        n=n/num;
    }
    int j;
    for(j=i-1;j>=0;j--)
    printf("%c",s[j]);
}
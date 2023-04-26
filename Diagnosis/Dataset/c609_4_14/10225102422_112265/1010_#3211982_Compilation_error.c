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
    while(n!=0)
    {
        y=n - (n/num)*num;
        n=n/num;
        if(y<0)
        {y=y-b;n=n+1;
        if(y<=9&&y>=0)
        s[i]='0'+y;
        else 
        s[i]='A'+y-10;
        i++;
        
    }
    int j;
    for(j=i-1;j>=0;j--)
    printf("%c",s[j]);
}
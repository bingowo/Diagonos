#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
//int gcd(int a,int b)
//{
//    if(b==0)return a;
//    else return gcd(b,a%b);
//}
int t[40];
void change(int x,int y)
{
    int i=0;
    do
    {
        t[i++]=x%2;
        x/=2;
    }while(x!=0);
    while(i<=y-1) t[i++]=0;
    for(int j=i-1;j>=0;j--)
    {
        printf("%d",t[j]);
    }
}
int main()
{
    char s[510];
    scanf("%s",s);
    printf("0001");
    int len=strlen(s);
    change(len,10);
    for(int i=0;i<strlen(s);i+=3)
    {
        if(i==strlen(s)-1)
        {
            int x=s[i]-'0';
            change(x,4);
        }
        else if( i==strlen(s)-2)
        {
             int x=(s[i]-'0')*10+s[i+1]-'0';
             change(x,7);
        }
        else
        {
            int x=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';
            change(x,10);
        }
    }
    return 0;
}


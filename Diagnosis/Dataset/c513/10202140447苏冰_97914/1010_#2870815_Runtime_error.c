#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ans[700]="0001";
char table[]="01";
void r(int n,int m)
{
    void reverse(char s[]);
    int i=0;
    char s[10]={0};
    while(n!=0)
    {
        s[i]=table[n%2];
        n=n/2;
        i++;
    }
    while(i<3*m+1)
    {
        s[i]='0';
        i++;
    }
    reverse(s);
    strcat(ans,s);
}
void reverse(char s[])
{
    int c,i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
int main()
{
     char n[550];
     scanf("%s",n);
     int len=strlen(n);
     r(len,3);
     int i=0;
     for(i=0;i<len-2;i+=3)
     {
         int num1=(n[i]-'0')*100+(n[i+1]-'0')*10+(n[i+2]-'0');
         r(num1,3);
     }
     int m=len%3;
     int num2;
     if(m==2)
     {
        num2 = (n[i]-'0')*10+n[i+1]-'0';
         r(num2,m);
     }
     if(m==1)
     {
        num2 = n[i]-'0';
          r(num2,m);
     }
     for(int i=0;i<strlen(ans);i++)
     {
         if(ans[i]=='0' || ans[i]=='1')
         {
              printf("%c",ans[i]);
         }
     }
     return 0;
}

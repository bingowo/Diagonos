#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[10000];
    int f[10000]={0};
    scanf("%s",s);
    int point=0,i=0,flag,k=0,r;
    long long int a=0,b=0,qr,qi;
    if(s[0]=='-')
    {
        point=1;
        i++;
    }    
    for(;i<strlen(s);i++)
    {
        if(s[i]=='-')
        {
            flag=1;
            break;
        }
        if(s[i]=='+')break;
        a=a*10+s[i]-'0';
    }
    i++;
    for(;i<strlen(s);i++)
    {
        if(s[i]=='i')break;
        b=b*10+s[i]-'0';
    }
    if(point)a=-a;
    if(flag)b=-b;
    int top=0;
 while(a!=0||b!=0){
  long long lasa=a,lasb=b;
  if((a-b)%2 == 0) ans[++top]='0',a=(lasa-lasb)/-2,b=(lasa+lasb)/-2;
  else ans[++top]='1',a=(lasa-lasb-1)/-2,b=(lasa+lasb-1)/-2;
 }
 if(top==0) puts("0");
 while(top) printf("%c",ans[top--]);
 return 0;
    return 0;
}
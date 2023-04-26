#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
void reverse(char s[100])
{
int i,j;
    char t;
    j=strlen(s)-1;
    for(i=0;i<=j;i++,j--)
    {
        t=s[i];s[i]=s[j];s[j]=t;
    }

}
int main()
{
   char s[1000],t[1000];
   int i=0,sign1,sign2,h;
   long long int a,b,qr,qi;
   int r,k=0;
   scanf("%s",s);
   for(i=0;isspace(s[i]);i++);
   sign1=(s[i]=='-')?-1:1;
   if(s[i]=='-')i++;
   for(h=0;isdigit(s[i]);i++)h++;
   if(s[i]!='i'){i=i-h;for(a=0;isdigit(s[i]);i++)a=a*10+s[i]-'0';a=a*sign1;}
  else {a=0;i=i-h-1;if(i<0)i=0;}
     sign2=(s[i]=='-')?-1:1;
       if(s[i]=='+'|| s[i]=='-')i++;
   if(s[i]=='i')b=1;
   else{for(b=0;isdigit(s[i]);i++)b=b*10+s[i]-'0';}
   b=b*sign2;
   if(a==0 && b==0){t[0]=0+'0';k++;}
   while(1)
   {
       if(a==0 && b==0)break;
       if(((a%2)==0 && (b%2)==0) ||(abs(a%2)==1 && abs(b%2)==1)){t[k]=0+'0';r=0;k++;qr=(r-a+b)/2;qi=(r-a-b)/2;a=qr;b=qi;}
       else{t[k]=1+'0';r=1;k++;qr=(r-a+b)/2;qi=(r-a-b)/2;a=qr;b=qi;}
   }
   t[k]=0;
   reverse(t);
   printf("%s\n",t);
    return 0;
}

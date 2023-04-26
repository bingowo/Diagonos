#include <stdio.h>
#include <stdlib.h>

int main()
{
   char s[10];
   scanf("%s",s);
   int i=0,d,k,j,m;int t[1000];
   long long qr=0,qi=0,a=0,b=0;
   for(i=2;s[i];i++)
   {
       if(s[i]>'A')d=s[i]-'A'+10;
       else d=s[i]-'0';
       j=8;
       for(k=0;k<4;k++)
       {
           if(d&j)t[(i-2)*4+k]=1;
           else t[(i-2)*4+k]=0;
           j=j>>1;
       }


   }
for(m=0;m<(i-2)*k;m++)
{
    a=t[m]-qr-qi;
    b=qr-qi;
    qr=a;
    qi=b;
}
if(a!=0 && b!=0)
{if(b==1)printf("%d""+""i",a);
else if(b==-1)printf("%d""-""i",a);
else if(b>0)printf("%d""+""%d""i",a,b);
else if(b<0)printf("%d%d""i",a,b);
}
else if(a==0)
{
    if(b==1)printf("+""i",a);
else if(b==-1)printf("-""i",a);
else if(b>0)printf("%d""i",b);
else if(b<0)printf("%d""i",b);
}
else printf("%d",a);
    return 0;
}

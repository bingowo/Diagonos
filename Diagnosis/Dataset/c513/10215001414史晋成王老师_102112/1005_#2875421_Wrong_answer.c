#include<stdio.h>
#include<stdlib.h>

int main()
{char s[100],c[300]; int T,a,b,i,j,k,number,t;
scanf("%d",&T);
for(i=0;i<T;i++)
  {scanf("%s",s);
   k=strlen(s)-1;
   
     number=0;
   for(;k>1;k--)
   { a=s[k]-'0'; j=0;
       do { 
      if (j<number)
      t=a*10+c[j]-'0';
      else
      t=a*10;
      c[j++]=t/8+'0';
      a=t%8;
      } while(a!=0||j<number);
      number=j;
   }
   c[number]='\0';
   printf("case #%d:\n",i);
   printf("%s\n",c);
  }
    
}
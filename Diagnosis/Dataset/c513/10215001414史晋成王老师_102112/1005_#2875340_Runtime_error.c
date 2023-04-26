#include<stdio.h>
#include<stdlib.h>

int main()
{char s[100],c[300]; int T,a,b,i,j,k,number,t;
scanf("%d",&T);
for(i=0;i<T;i++)
  {scanf("%s",s);
   k=0;
   while(s[k]!=EOF)
      { k++;
       }
     i=0;number=0;
   for(;k>1;k--)
   { a=s[k-1]-'0'; j=0;
       do
      { 
      if (j<number)
      t=a*10+c[j]-'0';
      else
      t=a*10;
      c[j++]=t/8;
      a=t%8;
      } while(a!=0||j<number);
      number=j;
   }
   c[number]='\0';
   printf("case #%d:\n",i);
   printf("%s",c);
  }
    
}
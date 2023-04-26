#include<stdio.h>
#include<stdlib.h>

int main()
{char s[100],c[300]; int T,a,b,i,j,k,number;
scanf("%d",&T);
for(i=0;i<T;i++)
  {scanf("%s",s);
   k=0;
   while(s[k]!=EOF)
      { k++;
       }
     i=0;j=0;number=0;a=s[k-1]-'0';
   for(;k>1;k--)
   {do
      { 
      if (j<number)
      i=a*10+c[j]-'0';
      else
      i=a*10;
      c[j++]=i/8;
      a=i%8;
      } while(a!=0||j<number)
      number=j;
   }
   c[number]='\0';
   printf("case #%d:\n",i);
   printf("%s",c);
  }
    
}
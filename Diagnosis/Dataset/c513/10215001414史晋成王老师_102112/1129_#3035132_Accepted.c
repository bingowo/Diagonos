#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ char c[12000],s[11000],s1[11000];
  int number,i,j,n,m,k,l,count;
  scanf("%s",s);
  l=strlen(s);
   i=0;
   number=0;count=0;
   while(s[i])
   { if(!isdigit(s[i])) 
     {number=0;
      c[count]=s[i];
      count++;
      if(isdigit(s[i+1])||i+1==l)
      {c[count]=0;count=0;}
     }
     else if(isdigit(s[i]))
     {number=number*10+s[i]-'0';
      if(!isdigit(s[i+1])||i+1==l)
      { for(j=0;j<number;j++)
          printf("%s",c);
          memset(c,0,sizeof(c));
      }
     }
     i++;
   }
   printf("%s",c);
}
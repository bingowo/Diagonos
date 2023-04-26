#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{ int T,i,j=0;
  char s[200];
  char *p;
  char m[200];
  scanf("%d\n",&T);
  for(i=0;i<=T;i++)
   { int k=0,r=0;
     int d,g;
     scanf("%s",s);
     p=s;
     while(*p) p++;
     while(*--p!='.')
     {
       d=*p-'0';
       while(d!=0||j<g)
        { if(j<r) g=d*10+m[j]-'0';
          else g=d*10;
          m[j++]=g/8+'0';
          d=g%8;
        }
       r=j;
     }
     m[r]='\0';
     printf("case #%d\n:",i);
     printf("0.");
     printf("%s\n",m);
    }
 return 0;
}
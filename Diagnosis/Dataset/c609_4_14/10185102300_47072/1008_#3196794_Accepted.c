#include <stdio.h>
#include <stdlib.h>
#define N 80
int main()
{  int i; 
   char s[N],buf[N],*p;
   while(scanf("%s",s)==1) 
  {   for (i=0;s[i];i++) if (s[i]=='.') break;
      if (s[i]) 
      { double f=atof(s);
        for (i=0;i<sizeof(double);i++)
          printf("%02x ",((unsigned char*)&f)[i]);
        printf("\n");
      }
      else
      { int d=atoi(s);
        for (i=0;i<sizeof(int);i++)
          printf("%02x ",((unsigned char*)&d)[i]);
        printf("\n");
      }
    }
 
  return 0;
}

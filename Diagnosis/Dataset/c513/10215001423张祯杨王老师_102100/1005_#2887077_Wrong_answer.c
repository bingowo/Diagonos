#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{ int T,i,j;
  char s[200];
  char *p;
  int m[200];
  scanf("%d\n",&T);
  for(i=0;i<T;i++)
   { scanf("%s",s);
     int len=strlen(s);
     int beichu,yu;
     for(j=2;j<len||yu==0;j++)
     { yu=s[2];
       if(s[j+1]!=0) beichu=yu*10+s[j+1];
       else beichu=yu*10;
       yu=beichu%8;
       m[j-2]=beichu/8;
     }
     printf("case #%d:\n",i);
     printf("0.");
     for(int n=0;n<j-2;n++) printf("%d",m[n]);
     printf("\n");
   }
 return 0;
}


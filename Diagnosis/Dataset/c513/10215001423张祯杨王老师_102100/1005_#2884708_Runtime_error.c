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
     for(j=2;j<len||yu!=0;j++)
     { yu=s[2];
       if(s[j+1]!=0) beichu=yu*10+s[j+1];
       else beichu=yu*10;
       s[j-2]=beichu%8;
       yu=beichu-8*s[j-2];
     }
     printf("case #%d\n:",i);
     printf("0.");
     for(int m=0;m<j-2;m++) printf("%d",s[m]);
   }
 return 0;
}

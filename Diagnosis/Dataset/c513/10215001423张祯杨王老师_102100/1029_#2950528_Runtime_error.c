#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char cmp(int m,char a[m][200])
{ int len=strlen(a[m]);
  for(int n=0;n<=len-1;n++)
  { if((int)a[m][n]>=65&&(int)a[m][n]<=90)
       { for(int q=n;q<=len-2;q++)
           { if((int)a[m][q+1]>=65&&(int)a[m][q+1]<=90)
             { if((int)a[m][n]>(int)a[m][q+1])
                 {  char r=a[m][n];
                     a[m][n]=a[m][q+1];
                     a[m][q+1]=r;
                 }
             }

           }
       }

  }
   for(int t=0;t<=len-1;t++) printf("%s",a[m][t]);
}
int main()
{ char s[10][200];
  int T;
  scanf("%d\n",&T);
  for(int i=1;i<=T;i++)
  {
      for(int m=0;s[i][m]!='\n';m++)  scanf("%s",&s[i][m]);
  }
  for(int i=1;i<=T;i++) cmp(i,s[i][200]);
  return 0;

}
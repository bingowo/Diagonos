#include <stdio.h>
#include <string.h>

#define N 50

int max(int a,int b) { return a>b ? a : b; }

int fenceLen(char* s)
{  char *p=s; if (*p!='-'&&*p!='|') return 0;
   while (*(p+1)&&*p!=*(p+1)) p++;
   return max(p+1-s,fenceLen(p+1));
}

int main()
{  char s[N+1];
   fgets(s,sizeof(s),stdin), s[strlen(s)-1]=0;
   printf("%d\n",fenceLen(s));
   return 0;
}
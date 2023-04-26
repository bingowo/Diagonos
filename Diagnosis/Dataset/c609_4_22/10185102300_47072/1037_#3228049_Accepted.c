#include <stdio.h>
#include <string.h>

#define N 1000000

int find(char*s,int n,char c)
{ int i; for (i=0;i<n;i++) if (s[i]==c) return 1; return 0;}

int main()
{ char *s=(char*)malloc(N+1),*p,longs[63]="",t[63]; int tn,i;
   scanf("%s",s);
   for (i=0;s[i];i++)
   {  *t=tn=0; p=s+i;
       while (!find(t,tn,*p)&&*p) t[tn++]=*p++; t[tn]=0;
       if (strlen(t)>strlen(longs)) strcpy(longs,t);
   }

    printf("%s\n",longs);
   return 0;
}
#include <stdio.h>
#include <string.h>

#define N 500

int cmp(const void* e1,const void* e2)
{
    return strcmp((char*)e1,(char*)e2);
}
int find(char*s,char c)
{ int i; for (i=0;i<strlen(s);i++) if (s[i]==c) return 1; return 0;}

void solve()
{  char s[N+1], *p=s, a[N/2][N+1]={0}; int n=0,tn,i;
   static const char *sep=" ,.!?";

   fgets(s,sizeof s,stdin); if (s[strlen(s)-1]=='\n') s[strlen(s)-1]=0;

   while (*p)
   {  *a[n]=tn=0;
       while (!find(sep,*p)&&*p) a[n][tn++]=*p++; a[n++][tn]=0;
       while (find(sep,*p)&&*p) p++;
   }

   qsort(a,n,sizeof a[0],cmp);

   for(i=0;i<n;i++)
       if (i==n-1) printf("%s\n",a[i]);
       else if (strcmp(a[i],a[i+1])) printf("%s ",a[i]);

}

int main()
{ int i,t;  scanf("%d\n",&t);
   for (i=0;i<t;i++) printf("case #%d:\n",i),solve();
   return 0;
}
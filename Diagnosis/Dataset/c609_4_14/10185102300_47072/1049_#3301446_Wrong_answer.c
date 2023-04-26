#include <stdio.h>
#define N 500
typedef struct { int cnt,v[N]; } BIGINT ;

int isGE(BIGINT a,BIGINT b)
{  int i;
   if (a.cnt!=b.cnt) return a.cnt>b.cnt?1:0;
   for (i=0;i<a.cnt;i++) if (a.v[i]!=b.v[i]) return a.v[i]>b.v[i]?1:0;
   return 1;
}

BIGINT MINUS(BIGINT a,BIGINT b)
{ BIGINT R=a; int *pa=a.v,*pb=b.v,*pR=R.v,*pt=R.v,i;
   for (i=0;i<a.cnt;i++)  { int t=i<b.cnt?*pb:0; if ((*pR=*pa-t)<0) *pR+=10, --*(pa+1);++pa;++pb,++pR; }
   for (pR=R.v+a.cnt-1;pR>R.v&&*pR==0;pR--) R.cnt--;
   return R;
}

void printBIGINT(BIGINT R) {  int i;  for (i=R.cnt-1;i>=0;i--) printf("%d",R.v[i]); }

BIGINT inputBIGINT(char *p)
{ BIGINT R={0};int i; R.cnt=strlen(p);
   for (i=R.cnt-1;i>=0;i--)
    R.v[i]=*p++-'0';
   return R;
}


int main()
{   char sa[N+1], sb[N+1];
    while (scanf("%s%s",sa,sb)==2)
    {  BIGINT a=inputBIGINT(sa),b=inputBIGINT(sb);
       if (isGE(a,b)) printBIGINT(MINUS(a,b));
       else  printf("-"),printBIGINT(MINUS(b,a));
       printf("\n");
    }
    return 0;
}
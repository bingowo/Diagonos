#include <stdio.h>
#include <string.h>

#define LN  1000
#define N     80
#define M   2000



void solve()
{ int m,n=0,j,nWords=0,i,k; char line[M+2], L[LN][N+1],*p=line;
  char buf[N][N+1]; int linelen=0;

  scanf("%d\n",&m);
  fgets(line,sizeof line,stdin); if (line[strlen(line)-1]=='\n')line[strlen(line)-1]=0;
  while (*p)
  {  while (*p==' ') p++; j=0; if (*p==0) break;
     while (*p!=' '&&*p) L[n][j++]=*p++; L[n++][j]=0;
  }
  for(j=0;j<n;j++)
  {
     if (strlen(L[j])+linelen<m)
         {  linelen+=strlen(L[j])+(linelen!=0);
            strcpy(buf[nWords++],L[j]);
         }
    else { int spaces,nSep,nRemain;
      spaces=m-linelen+nWords-1;
      nSep=spaces/(nWords-1);
      nRemain=spaces%(nWords-1);
      for (i=0;i<nWords;i++)
      {  printf(buf[i]);
          if (i<nWords-1)
           if (i<nWords-1-nRemain)  for (k=0;k<nSep;k++) printf(" ");
            else for (k=0;k<nSep+1;k++) printf(" ");

       }
       printf("\n");nWords=0;
       strcpy(buf[nWords++],L[j]);linelen=strlen(L[j]);
    }
  }
        for (i=0;i<nWords;i++)  {  printf(buf[i]); if (i<nWords-1) printf(" "); else printf("\n"); }
 }


int main()
{  int i,t;
   scanf("%d\n",&t);
   for (i=0;i<t;i++)
   { printf("case #%d:\n",i);
     solve();
   }
   return 0;
}
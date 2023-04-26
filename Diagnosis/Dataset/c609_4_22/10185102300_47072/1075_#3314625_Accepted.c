#include<stdio.h>
#include<string.h>
#define N 80

int isLeft(int i,int j,char (*m)[N])
{ for (;j<N;j++) if (m[i][j]) break; return j!=N; }

void displayLine(int i,char (*m)[N])
{ int j; for (j=0;isLeft(i,j,m);j++) printf("%c",m[i][j]?m[i][j]:' '); printf("\n"); }

int main()
{ char s[N+1],m[2*N+1][N]; int line,i;
  while (scanf("%s",s)!=EOF)
  { for (memset(m,0,sizeof m),m[line=N][0]=s[0],i=1;i<strlen(s);m[line][i]=s[i],i++)
      if (s[i]>s[i-1]) line--; else if (s[i]<s[i-1]) line++;
    for (i=0;i<2*N+1;i++) if (isLeft(i,0,m)) displayLine(i,m);
  }
  return 0;
}
#include<stdio.h>
#include<string.h>
#define N 80

int isLeft(int i,int j,char (*m)[N])
{ for (;j<N;j++) if (m[i][j]) break; return j!=N; }
void displayLine(int i,char (*m)[N])
{ int j; for (j=0;isLeft(i,j,m);j++) printf("%c",m[i][j]?m[i][j]:' '); printf("\n"); }
void display(char* s)
{ int line=N,i=0;  char m[2*N+1][N]={0}; m[line][i]=s[i];
  for (i=1;i<strlen(s);m[line][i++]=s[i])
     if (s[i]>s[i-1]) line--; else if (s[i]<s[i-1]) line++;
  for (i=0;i<2*N+1;i++) if (isLeft(i,0,m)) displayLine(i,m);
}

int main()
{ char s[N+1];  while (scanf("%s",s)!=EOF) display(s);
  return 0;
}
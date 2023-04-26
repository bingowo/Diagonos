#include<stdio.h>
#define N 80

int main()
{ char s[N+1],m[2*N+1][N+1]; int i,j;
  while (scanf("%s",s)!=EOF)
  { for (memset(m,' ',sizeof m),m[i=N][0]=s[0],j=1;s[j];m[i][j]=s[j],j++)
      if (s[j]>s[j-1]) i--; else if (s[j]<s[j-1]) i++;
    for (i=0;i<2*N+1;i++)
    { for (j=N-1;j>=0&&m[i][j]==' ';j--);
      if (j>=(m[i][j+1]=0)) printf("%s\n",m[i]);
    }
  }
  return 0;
}
#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{int n,m,i,j,k=0,s[50][50],c;
 for(i=1;i<=31;i++)
 {for(j=1;j<=31;j++)
  {if(i<j) s[i][j]=0;
   else if(i==j) s[i][j]=1;
   else s[i][j]=2*s[i-1][j]-s[i-j-1][j]+pow(2,i-1-j);
  }
 }

do
{ scanf("%d%d",&n,&m);
  if(n!=-1&&m!=-1)
  {c=s[n][m];
  printf("%d\n",c);
  }
}
 while(n!=-1&&m!=-1);
 return 0;
}

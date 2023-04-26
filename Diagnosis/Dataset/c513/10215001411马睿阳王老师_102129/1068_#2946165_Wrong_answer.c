#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{int n,m,i,j,k=0,s[50][50],c;
 for(i=0;i<n;i++)
 {for(j=0;j<m;j++)
  {if(i<j) s[i][j]=0;
   else if(i==j) s[i][j]=1;
   else s[i][j]=2*s[i-1][j]-s[i-j-1][j]+pow(2,i-1-j);
  }
 }

do
{ scanf("%d%d",&n,&m);
  c=s[n][m];
  printf("%d",c);
}
 while(n!=-1&&m!=-1);
 return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int n,m,k,i,j,a[1000][1000],b[100000];
scanf("%d %d %d",&n,&m,&k);
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
{ scanf("%d",&a[i][j]);
}
}
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
{ printf("%d ",a[i][j]);
}
printf("\n");
}    
}